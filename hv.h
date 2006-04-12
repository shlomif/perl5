/*    hv.h
 *
 *    Copyright (C) 1991, 1992, 1993, 1996, 1997, 1998, 1999,
 *    2000, 2001, 2002, 2005, by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 */

/* entry in hash value chain */
struct he {
    /* Keep hent_next first in this structure, because sv_free_arenas take
       advantage of this to share code between the he arenas and the SV
       body arenas  */
    HE		*hent_next;	/* next entry in chain */
    HEK		*hent_hek;	/* hash key */
    union {
	SV	*hent_val;	/* scalar value that was hashed */
	Size_t	hent_refcount;	/* references for this shared hash key */
    } he_valu;
};

/* hash key -- defined separately for use as shared pointer */
struct hek {
    U32		hek_hash;	/* hash of key */
    I32		hek_len;	/* length of hash key */
    char	hek_key[1];	/* variable-length hash key */
    /* the hash-key is \0-terminated */
    /* after the \0 there is a byte for flags, such as whether the key
       is UTF-8 */
};

struct shared_he {
    struct he shared_he_he;
    struct hek shared_he_hek;
};

/* Subject to change.
   Don't access this directly.
*/
struct xpvhv_aux {
    HEK		*xhv_name;	/* name, if a symbol table */
    AV		*xhv_backreferences; /* back references for weak references */
    HE		*xhv_eiter;	/* current entry of iterator */
    I32		xhv_riter;	/* current root of iterator */
};

/* hash structure: */
/* This structure must match the beginning of struct xpvmg in sv.h. */
struct xpvhv {
    union {
	NV	xnv_nv;		/* numeric value, if any */
	HV *	xgv_stash;
    }		xnv_u;
    STRLEN	xhv_fill;	/* how full xhv_array currently is */
    STRLEN	xhv_max;	/* subscript of last element of xhv_array */
    union {
	IV	xivu_iv;	/* integer value or pv offset */
	UV	xivu_uv;
	void *	xivu_p1;
	I32	xivu_i32;
	HEK *	xivu_namehek;
    }		xiv_u;
    union {
	MAGIC*	xmg_magic;	/* linked list of magicalness */
	HV*	xmg_ourstash;	/* Stash for our (when SvPAD_OUR is true) */
    } xmg_u;
    HV*		xmg_stash;	/* class package */
};

#define xhv_keys xiv_u.xivu_iv

#if 0
typedef struct xpvhv xpvhv_allocated;
#else
typedef struct {
    STRLEN	xhv_fill;	/* how full xhv_array currently is */
    STRLEN	xhv_max;	/* subscript of last element of xhv_array */
    union {
	IV	xivu_iv;	/* integer value or pv offset */
	UV	xivu_uv;
	void *	xivu_p1;
	I32	xivu_i32;
	HEK *	xivu_namehek;
    }		xiv_u;
    union {
	MAGIC*	xmg_magic;	/* linked list of magicalness */
	HV*	xmg_ourstash;	/* Stash for our (when SvPAD_OUR is true) */
    } xmg_u;
    HV*		xmg_stash;	/* class package */
} xpvhv_allocated;
#endif

/* hash a key */
/* FYI: This is the "One-at-a-Time" algorithm by Bob Jenkins
 * from requirements by Colin Plumb.
 * (http://burtleburtle.net/bob/hash/doobs.html) */
/* The use of a temporary pointer and the casting games
 * is needed to serve the dual purposes of
 * (a) the hashed data being interpreted as "unsigned char" (new since 5.8,
 *     a "char" can be either signed or unsigned, depending on the compiler)
 * (b) catering for old code that uses a "char"
 *
 * The "hash seed" feature was added in Perl 5.8.1 to perturb the results
 * to avoid "algorithmic complexity attacks".
 *
 * If USE_HASH_SEED is defined, hash randomisation is done by default
 * If USE_HASH_SEED_EXPLICIT is defined, hash randomisation is done
 * only if the environment variable PERL_HASH_SEED is set.
 * For maximal control, one can define PERL_HASH_SEED.
 * (see also perl.c:perl_parse()).
 */
#ifndef PERL_HASH_SEED
#   if defined(USE_HASH_SEED) || defined(USE_HASH_SEED_EXPLICIT)
#       define PERL_HASH_SEED	PL_hash_seed
#   else
#       define PERL_HASH_SEED	0
#   endif
#endif
#define PERL_HASH(hash,str,len) \
     STMT_START	{ \
	register const char * const s_PeRlHaSh_tmp = str; \
	register const unsigned char *s_PeRlHaSh = (const unsigned char *)s_PeRlHaSh_tmp; \
	register I32 i_PeRlHaSh = len; \
	register U32 hash_PeRlHaSh = PERL_HASH_SEED; \
	while (i_PeRlHaSh--) { \
	    hash_PeRlHaSh += *s_PeRlHaSh++; \
	    hash_PeRlHaSh += (hash_PeRlHaSh << 10); \
	    hash_PeRlHaSh ^= (hash_PeRlHaSh >> 6); \
	} \
	hash_PeRlHaSh += (hash_PeRlHaSh << 3); \
	hash_PeRlHaSh ^= (hash_PeRlHaSh >> 11); \
	(hash) = (hash_PeRlHaSh + (hash_PeRlHaSh << 15)); \
    } STMT_END

/* Only hv.c and mod_perl should be doing this.  */
#ifdef PERL_HASH_INTERNAL_ACCESS
#define PERL_HASH_INTERNAL(hash,str,len) \
     STMT_START	{ \
	register const char * const s_PeRlHaSh_tmp = str; \
	register const unsigned char *s_PeRlHaSh = (const unsigned char *)s_PeRlHaSh_tmp; \
	register I32 i_PeRlHaSh = len; \
	register U32 hash_PeRlHaSh = PL_rehash_seed; \
	while (i_PeRlHaSh--) { \
	    hash_PeRlHaSh += *s_PeRlHaSh++; \
	    hash_PeRlHaSh += (hash_PeRlHaSh << 10); \
	    hash_PeRlHaSh ^= (hash_PeRlHaSh >> 6); \
	} \
	hash_PeRlHaSh += (hash_PeRlHaSh << 3); \
	hash_PeRlHaSh ^= (hash_PeRlHaSh >> 11); \
	(hash) = (hash_PeRlHaSh + (hash_PeRlHaSh << 15)); \
    } STMT_END
#endif

/*
=head1 Hash Manipulation Functions

=for apidoc AmU||HEf_SVKEY
This flag, used in the length slot of hash entries and magic structures,
specifies the structure contains an C<SV*> pointer where a C<char*> pointer
is to be expected. (For information only--not to be used).

=head1 Handy Values

=for apidoc AmU||Nullhv
Null HV pointer.

=head1 Hash Manipulation Functions

=for apidoc Am|char*|HvNAME|HV* stash
Returns the package name of a stash, or NULL if C<stash> isn't a stash.
See C<SvSTASH>, C<CvSTASH>.

=for apidoc Am|void*|HeKEY|HE* he
Returns the actual pointer stored in the key slot of the hash entry. The
pointer may be either C<char*> or C<SV*>, depending on the value of
C<HeKLEN()>.  Can be assigned to.  The C<HePV()> or C<HeSVKEY()> macros are
usually preferable for finding the value of a key.

=for apidoc Am|STRLEN|HeKLEN|HE* he
If this is negative, and amounts to C<HEf_SVKEY>, it indicates the entry
holds an C<SV*> key.  Otherwise, holds the actual length of the key.  Can
be assigned to. The C<HePV()> macro is usually preferable for finding key
lengths.

=for apidoc Am|SV*|HeVAL|HE* he
Returns the value slot (type C<SV*>) stored in the hash entry.

=for apidoc Am|U32|HeHASH|HE* he
Returns the computed hash stored in the hash entry.

=for apidoc Am|char*|HePV|HE* he|STRLEN len
Returns the key slot of the hash entry as a C<char*> value, doing any
necessary dereferencing of possibly C<SV*> keys.  The length of the string
is placed in C<len> (this is a macro, so do I<not> use C<&len>).  If you do
not care about what the length of the key is, you may use the global
variable C<PL_na>, though this is rather less efficient than using a local
variable.  Remember though, that hash keys in perl are free to contain
embedded nulls, so using C<strlen()> or similar is not a good way to find
the length of hash keys. This is very similar to the C<SvPV()> macro
described elsewhere in this document.

=for apidoc Am|SV*|HeSVKEY|HE* he
Returns the key as an C<SV*>, or C<NULL> if the hash entry does not
contain an C<SV*> key.

=for apidoc Am|SV*|HeSVKEY_force|HE* he
Returns the key as an C<SV*>.  Will create and return a temporary mortal
C<SV*> if the hash entry contains only a C<char*> key.

=for apidoc Am|SV*|HeSVKEY_set|HE* he|SV* sv
Sets the key to a given C<SV*>, taking care to set the appropriate flags to
indicate the presence of an C<SV*> key, and returns the same
C<SV*>.

=cut
*/

/* these hash entry flags ride on hent_klen (for use only in magic/tied HVs) */
#define HEf_SVKEY	-2	/* hent_key is an SV* */


#define Nullhv Null(HV*)
#define HvARRAY(hv)	((hv)->sv_u.svu_hash)
#define HvFILL(hv)	((XPVHV*)  SvANY(hv))->xhv_fill
#define HvMAX(hv)	((XPVHV*)  SvANY(hv))->xhv_max
/* This quite intentionally does no flag checking first. That's your
   responsibility.  */
#define HvAUX(hv)	((struct xpvhv_aux*)&(HvARRAY(hv)[HvMAX(hv)+1]))
#define HvRITER(hv)	(*Perl_hv_riter_p(aTHX_ (HV*)(hv)))
#define HvEITER(hv)	(*Perl_hv_eiter_p(aTHX_ (HV*)(hv)))
#define HvRITER_set(hv,r)	Perl_hv_riter_set(aTHX_ (HV*)(hv), r)
#define HvEITER_set(hv,e)	Perl_hv_eiter_set(aTHX_ (HV*)(hv), e)
#define HvRITER_get(hv)	(SvOOK(hv) ? HvAUX(hv)->xhv_riter : -1)
#define HvEITER_get(hv)	(SvOOK(hv) ? HvAUX(hv)->xhv_eiter : 0)
#define HvNAME(hv)	HvNAME_get(hv)
/* FIXME - all of these should use a UTF8 aware API, which should also involve
   getting the length. */
/* This macro may go away without notice.  */
#define HvNAME_HEK(hv) (SvOOK(hv) ? HvAUX(hv)->xhv_name : 0)
#define HvNAME_get(hv)	((SvOOK(hv) && (HvAUX(hv)->xhv_name)) \
			 ? HEK_KEY(HvAUX(hv)->xhv_name) : 0)
#define HvNAMELEN_get(hv)	((SvOOK(hv) && (HvAUX(hv)->xhv_name)) \
				 ? HEK_LEN(HvAUX(hv)->xhv_name) : 0)

/* the number of keys (including any placeholers) */
#define XHvTOTALKEYS(xhv)	((xhv)->xhv_keys)

/*
 * HvKEYS gets the number of keys that actually exist(), and is provided
 * for backwards compatibility with old XS code. The core uses HvUSEDKEYS
 * (keys, excluding placeholdes) and HvTOTALKEYS (including placeholders)
 */
#define HvKEYS(hv)		HvUSEDKEYS(hv)
#define HvUSEDKEYS(hv)		(HvTOTALKEYS(hv) - HvPLACEHOLDERS_get(hv))
#define HvTOTALKEYS(hv)		XHvTOTALKEYS((XPVHV*)  SvANY(hv))
#define HvPLACEHOLDERS(hv)	(*Perl_hv_placeholders_p(aTHX_ (HV*)hv))
#define HvPLACEHOLDERS_get(hv)	(SvMAGIC(hv) ? Perl_hv_placeholders_get(aTHX_ (HV*)hv) : 0)
#define HvPLACEHOLDERS_set(hv,p)	Perl_hv_placeholders_set(aTHX_ (HV*)hv, p)

#define HvSHAREKEYS(hv)		(SvFLAGS(hv) & SVphv_SHAREKEYS)
#define HvSHAREKEYS_on(hv)	(SvFLAGS(hv) |= SVphv_SHAREKEYS)
#define HvSHAREKEYS_off(hv)	(SvFLAGS(hv) &= ~SVphv_SHAREKEYS)

/* This is an optimisation flag. It won't be set if all hash keys have a 0
 * flag. Currently the only flags relate to utf8.
 * Hence it won't be set if all keys are 8 bit only. It will be set if any key
 * is utf8 (including 8 bit keys that were entered as utf8, and need upgrading
 * when retrieved during iteration. It may still be set when there are no longer
 * any utf8 keys.
 * See HVhek_ENABLEHVKFLAGS for the trigger.
 */
#define HvHASKFLAGS(hv)		(SvFLAGS(hv) & SVphv_HASKFLAGS)
#define HvHASKFLAGS_on(hv)	(SvFLAGS(hv) |= SVphv_HASKFLAGS)
#define HvHASKFLAGS_off(hv)	(SvFLAGS(hv) &= ~SVphv_HASKFLAGS)

#define HvLAZYDEL(hv)		(SvFLAGS(hv) & SVphv_LAZYDEL)
#define HvLAZYDEL_on(hv)	(SvFLAGS(hv) |= SVphv_LAZYDEL)
#define HvLAZYDEL_off(hv)	(SvFLAGS(hv) &= ~SVphv_LAZYDEL)

#define HvREHASH(hv)		(SvFLAGS(hv) & SVphv_REHASH)
#define HvREHASH_on(hv)		(SvFLAGS(hv) |= SVphv_REHASH)
#define HvREHASH_off(hv)	(SvFLAGS(hv) &= ~SVphv_REHASH)

#define Nullhe Null(HE*)
#define HeNEXT(he)		(he)->hent_next
#define HeKEY_hek(he)		(he)->hent_hek
#define HeKEY(he)		HEK_KEY(HeKEY_hek(he))
#define HeKEY_sv(he)		(*(SV**)HeKEY(he))
#define HeKLEN(he)		HEK_LEN(HeKEY_hek(he))
#define HeKUTF8(he)  HEK_UTF8(HeKEY_hek(he))
#define HeKWASUTF8(he)  HEK_WASUTF8(HeKEY_hek(he))
#define HeKREHASH(he)  HEK_REHASH(HeKEY_hek(he))
#define HeKLEN_UTF8(he)  (HeKUTF8(he) ? -HeKLEN(he) : HeKLEN(he))
#define HeKFLAGS(he)  HEK_FLAGS(HeKEY_hek(he))
#define HeVAL(he)		(he)->he_valu.hent_val
#define HeHASH(he)		HEK_HASH(HeKEY_hek(he))
#define HePV(he,lp)		((HeKLEN(he) == HEf_SVKEY) ?		\
				 SvPV(HeKEY_sv(he),lp) :		\
				 (((lp = HeKLEN(he)) >= 0) ?		\
				  HeKEY(he) : NULL))

#define HeSVKEY(he)		((HeKEY(he) && 				\
				  HeKLEN(he) == HEf_SVKEY) ?		\
				 HeKEY_sv(he) : NULL)

#define HeSVKEY_force(he)	(HeKEY(he) ?				\
				 ((HeKLEN(he) == HEf_SVKEY) ?		\
				  HeKEY_sv(he) :			\
				  sv_2mortal(newSVpvn(HeKEY(he),	\
						     HeKLEN(he)))) :	\
				 &PL_sv_undef)
#define HeSVKEY_set(he,sv)	((HeKLEN(he) = HEf_SVKEY), (HeKEY_sv(he) = sv))

#define Nullhek Null(HEK*)
#define HEK_BASESIZE		STRUCT_OFFSET(HEK, hek_key[0])
#define HEK_HASH(hek)		(hek)->hek_hash
#define HEK_LEN(hek)		(hek)->hek_len
#define HEK_KEY(hek)		(hek)->hek_key
#define HEK_FLAGS(hek)	(*((unsigned char *)(HEK_KEY(hek))+HEK_LEN(hek)+1))

#define HVhek_UTF8	0x01 /* Key is utf8 encoded. */
#define HVhek_WASUTF8	0x02 /* Key is bytes here, but was supplied as utf8. */
#define HVhek_REHASH	0x04 /* This key is in an hv using a custom HASH . */
#define HVhek_FREEKEY	0x100 /* Internal flag to say key is malloc()ed.  */
#define HVhek_PLACEHOLD	0x200 /* Internal flag to create placeholder.
                               * (may change, but Storable is a core module) */
#define HVhek_MASK	0xFF

/* Which flags enable HvHASKFLAGS? Somewhat a hack on a hack, as
   HVhek_REHASH is only needed because the rehash flag has to be duplicated
   into all keys as hv_iternext has no access to the hash flags. At this
   point Storable's tests get upset, because sometimes hashes are "keyed"
   and sometimes not, depending on the order of data insertion, and whether
   it triggered rehashing. So currently HVhek_REHAS is exempt.
*/
   
#define HVhek_ENABLEHVKFLAGS	(HVhek_MASK - HVhek_REHASH)

#define HEK_UTF8(hek)		(HEK_FLAGS(hek) & HVhek_UTF8)
#define HEK_UTF8_on(hek)	(HEK_FLAGS(hek) |= HVhek_UTF8)
#define HEK_UTF8_off(hek)	(HEK_FLAGS(hek) &= ~HVhek_UTF8)
#define HEK_WASUTF8(hek)	(HEK_FLAGS(hek) & HVhek_WASUTF8)
#define HEK_WASUTF8_on(hek)	(HEK_FLAGS(hek) |= HVhek_WASUTF8)
#define HEK_WASUTF8_off(hek)	(HEK_FLAGS(hek) &= ~HVhek_WASUTF8)
#define HEK_REHASH(hek)		(HEK_FLAGS(hek) & HVhek_REHASH)
#define HEK_REHASH_on(hek)	(HEK_FLAGS(hek) |= HVhek_REHASH)

/* calculate HV array allocation */
#ifndef PERL_USE_LARGE_HV_ALLOC
/* Default to allocating the correct size - default to assuming that malloc()
   is not broken and is efficient at allocating blocks sized at powers-of-two.
*/   
#  define PERL_HV_ARRAY_ALLOC_BYTES(size) ((size) * sizeof(HE*))
#else
#  define MALLOC_OVERHEAD 16
#  define PERL_HV_ARRAY_ALLOC_BYTES(size) \
			(((size) < 64)					\
			 ? (size) * sizeof(HE*)				\
			 : (size) * sizeof(HE*) * 2 - MALLOC_OVERHEAD)
#endif

/* Flags for hv_iternext_flags.  */
#define HV_ITERNEXT_WANTPLACEHOLDERS	0x01	/* Don't skip placeholders.  */

#define hv_iternext(hv)	hv_iternext_flags(hv, 0)
#define hv_magic(hv, gv, how) sv_magic((SV*)(hv), (SV*)(gv), how, NULL, 0)

/* available as a function in hv.c */
#define Perl_sharepvn(sv, len, hash) HEK_KEY(share_hek(sv, len, hash))
#define sharepvn(sv, len, hash)	     Perl_sharepvn(sv, len, hash)

#define share_hek_hek(hek)						\
    (++(((struct shared_he *)(((char *)hek)				\
			      - STRUCT_OFFSET(struct shared_he,		\
					      shared_he_hek)))		\
	->shared_he_he.he_valu.hent_refcount),				\
     hek)

/* This refcounted he structure is used for storing the hints used for lexical
   pragmas. Without threads, it's basically struct he + refcount.
   With threads, life gets more complex as the structure needs to be shared
   between threads (because it hangs from OPs, which are shared), hence the
   alternate definition and mutex.  */

#ifdef PERL_CORE

/* Gosh. This really isn't a good name any longer.  */
struct refcounted_he {
    struct refcounted_he *refcounted_he_next;	/* next entry in chain */
#ifdef USE_ITHREADS
    U32                   refcounted_he_hash;
    U32                   refcounted_he_keylen;
#else
    HEK                  *refcounted_he_hek;	/* hint key */
#endif
    U32	                  refcounted_he_refcnt;	/* reference count */
    union {
	IV                refcounted_he_u_iv;
	UV                refcounted_he_u_uv;
	STRLEN            refcounted_he_u_len;
    } refcounted_he_val;
    /* First byte is flags. Then NUL-terminated value. Then for ithreads,
       non-NUL terminated key.  */
    char                  refcounted_he_data[1];
};

/* Flag bits are HVhek_UTF8, HVhek_WASUTF8, then */
#define HVrhek_undef	0x00 /* Value is undef. */
#define HVrhek_PV	0x10 /* Value is a string. */
#define HVrhek_IV	0x20 /* Value is IV/UV. */
#define HVrhek_delete	0x30 /* Value is placeholder - signifies delete. */
#define HVrhek_typemask	0x30
#define HVrhek_UTF8	0x40 /* string value is utf8. */
#define HVrhek_UV	0x40 /* integer value is UV. */

#  ifdef USE_ITHREADS
#    define HINTS_REFCNT_LOCK		MUTEX_LOCK(&PL_hints_mutex)
#    define HINTS_REFCNT_UNLOCK		MUTEX_UNLOCK(&PL_hints_mutex)
#  else
#    define HINTS_REFCNT_LOCK		NOOP
#    define HINTS_REFCNT_UNLOCK		NOOP
#  endif
#endif

#ifdef USE_ITHREADS
#  define HINTS_REFCNT_INIT		MUTEX_INIT(&PL_hints_mutex)
#  define HINTS_REFCNT_TERM		MUTEX_DESTROY(&PL_hints_mutex)
#else
#  define HINTS_REFCNT_INIT		NOOP
#  define HINTS_REFCNT_TERM		NOOP
#endif

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 *
 * ex: set ts=8 sts=4 sw=4 noet:
 */
