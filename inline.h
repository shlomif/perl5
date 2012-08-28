/*    inline.h
 *
 *    Copyright (C) 2012 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * This file is a home for static inline functions that cannot go in other
 * headers files, because they depend on proto.h (included after most other
 * headers) or struct definitions.
 *
 * Each section names the header file that the functions "belong" to.
 */

/* ------------------------------- cv.h ------------------------------- */

PERL_STATIC_INLINE I32 *
S_CvDEPTHp(const CV * const sv)
{
    assert(SvTYPE(sv) == SVt_PVCV || SvTYPE(sv) == SVt_PVFM);
    return SvTYPE(sv) == SVt_PVCV
	? &((XPVCV*)SvANY(sv))->xcv_depth
	: &((XPVCV*)SvANY(sv))->xpv_fmdepth;
}

/* ------------------------------- sv.h ------------------------------- */

PERL_STATIC_INLINE SV *
S_SvREFCNT_inc(SV *sv)
{
    if (sv)
	SvREFCNT(sv)++;
    return sv;
}
PERL_STATIC_INLINE SV *
S_SvREFCNT_inc_NN(SV *sv)
{
    SvREFCNT(sv)++;
    return sv;
}
PERL_STATIC_INLINE void
S_SvREFCNT_inc_void(SV *sv)
{
    if (sv)
	SvREFCNT(sv)++;
}
PERL_STATIC_INLINE void
S_SvREFCNT_dec(pTHX_ SV *sv)
{
    if (sv) {
	if (SvREFCNT(sv)) {
	    if (--(SvREFCNT(sv)) == 0)
		Perl_sv_free2(aTHX_ sv);
	} else {
	    sv_free(sv);
	}
    }
}

PERL_STATIC_INLINE void
SvAMAGIC_on(SV *sv)
{
    assert(SvROK(sv));
    if (SvOBJECT(SvRV(sv))) HvAMAGIC_on(SvSTASH(SvRV(sv)));
}
PERL_STATIC_INLINE void
SvAMAGIC_off(SV *sv)
{
    if (SvROK(sv) && SvOBJECT(SvRV(sv)))
	HvAMAGIC_off(SvSTASH(SvRV(sv)));
}

PERL_STATIC_INLINE U32
S_SvPADTMP_on(SV *sv)
{
    assert(!(SvFLAGS(sv) & SVs_PADMY));
    return SvFLAGS(sv) |= SVs_PADTMP;
}
PERL_STATIC_INLINE U32
S_SvPADTMP_off(SV *sv)
{
    assert(!(SvFLAGS(sv) & SVs_PADMY));
    return SvFLAGS(sv) &= ~SVs_PADTMP;
}
PERL_STATIC_INLINE U32
S_SvPADSTALE_on(SV *sv)
{
    assert(SvFLAGS(sv) & SVs_PADMY);
    return SvFLAGS(sv) |= SVs_PADSTALE;
}
PERL_STATIC_INLINE U32
S_SvPADSTALE_off(SV *sv)
{
    assert(SvFLAGS(sv) & SVs_PADMY);
    return SvFLAGS(sv) &= ~SVs_PADSTALE;
}
