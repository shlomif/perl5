/*  -*- buffer-read-only: t -*-
 *
 *    embedvar.h
 *
 *    Copyright (C) 1993, 1994, 1995, 1996, 1997, 1998, 1999,
 *    2000, 2001, 2002, 2003, 2004, 2005, by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by embed.pl from data in embed.fnc, embed.pl,
 * pp.sym, intrpvar.h, perlvars.h and thrdvar.h.
 * Any changes made here will be lost!
 *
 * Edit those files and run 'make regen_headers' to effect changes.
 */

/* (Doing namespace management portably in C is really gross.) */

/*
   The following combinations of MULTIPLICITY and PERL_IMPLICIT_CONTEXT
   are supported:
     1) none
     2) MULTIPLICITY	# supported for compatibility
     3) MULTIPLICITY && PERL_IMPLICIT_CONTEXT

   All other combinations of these flags are errors.

   only #3 is supported directly, while #2 is a special
   case of #3 (supported by redefining vTHX appropriately).
*/

#if defined(MULTIPLICITY)
/* cases 2 and 3 above */

#  if defined(PERL_IMPLICIT_CONTEXT)
#    define vTHX	aTHX
#  else
#    define vTHX	PERL_GET_INTERP
#  endif

#define PL_Sv			(vTHX->TSv)
#define PL_Xpv			(vTHX->TXpv)
#define PL_av_fetch_sv		(vTHX->Tav_fetch_sv)
#define PL_bodytarget		(vTHX->Tbodytarget)
#define PL_bostr		(vTHX->Tbostr)
#define PL_chopset		(vTHX->Tchopset)
#define PL_colors		(vTHX->Tcolors)
#define PL_colorset		(vTHX->Tcolorset)
#define PL_curcop		(vTHX->Tcurcop)
#define PL_curpad		(vTHX->Tcurpad)
#define PL_curpm		(vTHX->Tcurpm)
#define PL_curstack		(vTHX->Tcurstack)
#define PL_curstackinfo		(vTHX->Tcurstackinfo)
#define PL_curstash		(vTHX->Tcurstash)
#define PL_defoutgv		(vTHX->Tdefoutgv)
#define PL_defstash		(vTHX->Tdefstash)
#define PL_delaymagic		(vTHX->Tdelaymagic)
#define PL_dirty		(vTHX->Tdirty)
#define PL_dumpindent		(vTHX->Tdumpindent)
#define PL_efloatbuf		(vTHX->Tefloatbuf)
#define PL_efloatsize		(vTHX->Tefloatsize)
#define PL_errors		(vTHX->Terrors)
#define PL_firstgv		(vTHX->Tfirstgv)
#define PL_formtarget		(vTHX->Tformtarget)
#define PL_hv_fetch_ent_mh	(vTHX->Thv_fetch_ent_mh)
#define PL_hv_fetch_sv		(vTHX->Thv_fetch_sv)
#define PL_in_eval		(vTHX->Tin_eval)
#define PL_last_in_gv		(vTHX->Tlast_in_gv)
#define PL_lastgotoprobe	(vTHX->Tlastgotoprobe)
#define PL_lastscream		(vTHX->Tlastscream)
#define PL_localizing		(vTHX->Tlocalizing)
#define PL_mainstack		(vTHX->Tmainstack)
#define PL_markstack		(vTHX->Tmarkstack)
#define PL_markstack_max	(vTHX->Tmarkstack_max)
#define PL_markstack_ptr	(vTHX->Tmarkstack_ptr)
#define PL_maxscream		(vTHX->Tmaxscream)
#define PL_modcount		(vTHX->Tmodcount)
#define PL_na			(vTHX->Tna)
#define PL_nrs			(vTHX->Tnrs)
#define PL_ofs_sv		(vTHX->Tofs_sv)
#define PL_op			(vTHX->Top)
#define PL_opsave		(vTHX->Topsave)
#define PL_peepp		(vTHX->Tpeepp)
#define PL_reg_call_cc		(vTHX->Treg_call_cc)
#define PL_reg_curpm		(vTHX->Treg_curpm)
#define PL_reg_eval_set		(vTHX->Treg_eval_set)
#define PL_reg_flags		(vTHX->Treg_flags)
#define PL_reg_ganch		(vTHX->Treg_ganch)
#define PL_reg_leftiter		(vTHX->Treg_leftiter)
#define PL_reg_magic		(vTHX->Treg_magic)
#define PL_reg_match_utf8	(vTHX->Treg_match_utf8)
#define PL_reg_maxiter		(vTHX->Treg_maxiter)
#define PL_reg_oldcurpm		(vTHX->Treg_oldcurpm)
#define PL_reg_oldpos		(vTHX->Treg_oldpos)
#define PL_reg_oldsaved		(vTHX->Treg_oldsaved)
#define PL_reg_oldsavedlen	(vTHX->Treg_oldsavedlen)
#define PL_reg_poscache		(vTHX->Treg_poscache)
#define PL_reg_poscache_size	(vTHX->Treg_poscache_size)
#define PL_reg_re		(vTHX->Treg_re)
#define PL_reg_start_tmp	(vTHX->Treg_start_tmp)
#define PL_reg_start_tmpl	(vTHX->Treg_start_tmpl)
#define PL_reg_starttry		(vTHX->Treg_starttry)
#define PL_reg_sv		(vTHX->Treg_sv)
#define PL_regbol		(vTHX->Tregbol)
#define PL_regcc		(vTHX->Tregcc)
#define PL_regcompp		(vTHX->Tregcompp)
#define PL_regdata		(vTHX->Tregdata)
#define PL_regdummy		(vTHX->Tregdummy)
#define PL_regendp		(vTHX->Tregendp)
#define PL_regeol		(vTHX->Tregeol)
#define PL_regexecp		(vTHX->Tregexecp)
#define PL_regfree		(vTHX->Tregfree)
#define PL_regindent		(vTHX->Tregindent)
#define PL_reginput		(vTHX->Treginput)
#define PL_regint_start		(vTHX->Tregint_start)
#define PL_regint_string	(vTHX->Tregint_string)
#define PL_reginterp_cnt	(vTHX->Treginterp_cnt)
#define PL_reglastcloseparen	(vTHX->Treglastcloseparen)
#define PL_reglastparen		(vTHX->Treglastparen)
#define PL_regnarrate		(vTHX->Tregnarrate)
#define PL_regnpar		(vTHX->Tregnpar)
#define PL_regprecomp		(vTHX->Tregprecomp)
#define PL_regprogram		(vTHX->Tregprogram)
#define PL_regsize		(vTHX->Tregsize)
#define PL_regstartp		(vTHX->Tregstartp)
#define PL_regtill		(vTHX->Tregtill)
#define PL_restartop		(vTHX->Trestartop)
#define PL_rs			(vTHX->Trs)
#define PL_savestack		(vTHX->Tsavestack)
#define PL_savestack_ix		(vTHX->Tsavestack_ix)
#define PL_savestack_max	(vTHX->Tsavestack_max)
#define PL_scopestack		(vTHX->Tscopestack)
#define PL_scopestack_ix	(vTHX->Tscopestack_ix)
#define PL_scopestack_max	(vTHX->Tscopestack_max)
#define PL_screamfirst		(vTHX->Tscreamfirst)
#define PL_screamnext		(vTHX->Tscreamnext)
#define PL_secondgv		(vTHX->Tsecondgv)
#define PL_sortcop		(vTHX->Tsortcop)
#define PL_sortstash		(vTHX->Tsortstash)
#define PL_stack_base		(vTHX->Tstack_base)
#define PL_stack_max		(vTHX->Tstack_max)
#define PL_stack_sp		(vTHX->Tstack_sp)
#define PL_start_env		(vTHX->Tstart_env)
#define PL_statbuf		(vTHX->Tstatbuf)
#define PL_statcache		(vTHX->Tstatcache)
#define PL_statgv		(vTHX->Tstatgv)
#define PL_statname		(vTHX->Tstatname)
#define PL_tainted		(vTHX->Ttainted)
#define PL_timesbuf		(vTHX->Ttimesbuf)
#define PL_tmps_floor		(vTHX->Ttmps_floor)
#define PL_tmps_ix		(vTHX->Ttmps_ix)
#define PL_tmps_max		(vTHX->Ttmps_max)
#define PL_tmps_stack		(vTHX->Ttmps_stack)
#define PL_top_env		(vTHX->Ttop_env)
#define PL_toptarget		(vTHX->Ttoptarget)
#define PL_watchaddr		(vTHX->Twatchaddr)
#define PL_watchok		(vTHX->Twatchok)

/* cases 2 and 3 above */

#define PL_Argv			(vTHX->IArgv)
#define PL_Cmd			(vTHX->ICmd)
#define PL_DBassertion		(vTHX->IDBassertion)
#define PL_DBcv			(vTHX->IDBcv)
#define PL_DBgv			(vTHX->IDBgv)
#define PL_DBline		(vTHX->IDBline)
#define PL_DBsignal		(vTHX->IDBsignal)
#define PL_DBsingle		(vTHX->IDBsingle)
#define PL_DBsub		(vTHX->IDBsub)
#define PL_DBtrace		(vTHX->IDBtrace)
#define PL_Dir			(vTHX->IDir)
#define PL_Env			(vTHX->IEnv)
#define PL_LIO			(vTHX->ILIO)
#define PL_Mem			(vTHX->IMem)
#define PL_MemParse		(vTHX->IMemParse)
#define PL_MemShared		(vTHX->IMemShared)
#define PL_OpPtr		(vTHX->IOpPtr)
#define PL_OpSlab		(vTHX->IOpSlab)
#define PL_OpSpace		(vTHX->IOpSpace)
#define PL_Proc			(vTHX->IProc)
#define PL_Sock			(vTHX->ISock)
#define PL_StdIO		(vTHX->IStdIO)
#define PL_amagic_generation	(vTHX->Iamagic_generation)
#define PL_an			(vTHX->Ian)
#define PL_argvgv		(vTHX->Iargvgv)
#define PL_argvout_stack	(vTHX->Iargvout_stack)
#define PL_argvoutgv		(vTHX->Iargvoutgv)
#define PL_basetime		(vTHX->Ibasetime)
#define PL_beginav		(vTHX->Ibeginav)
#define PL_beginav_save		(vTHX->Ibeginav_save)
#define PL_bitcount		(vTHX->Ibitcount)
#define PL_body_arenaroots	(vTHX->Ibody_arenaroots)
#define PL_body_roots		(vTHX->Ibody_roots)
#define PL_bufend		(vTHX->Ibufend)
#define PL_bufptr		(vTHX->Ibufptr)
#define PL_checkav		(vTHX->Icheckav)
#define PL_checkav_save		(vTHX->Icheckav_save)
#define PL_clocktick		(vTHX->Iclocktick)
#define PL_collation_ix		(vTHX->Icollation_ix)
#define PL_collation_name	(vTHX->Icollation_name)
#define PL_collation_standard	(vTHX->Icollation_standard)
#define PL_collxfrm_base	(vTHX->Icollxfrm_base)
#define PL_collxfrm_mult	(vTHX->Icollxfrm_mult)
#define PL_compcv		(vTHX->Icompcv)
#define PL_compiling		(vTHX->Icompiling)
#define PL_comppad		(vTHX->Icomppad)
#define PL_comppad_name		(vTHX->Icomppad_name)
#define PL_comppad_name_fill	(vTHX->Icomppad_name_fill)
#define PL_comppad_name_floor	(vTHX->Icomppad_name_floor)
#define PL_cop_seqmax		(vTHX->Icop_seqmax)
#define PL_copline		(vTHX->Icopline)
#define PL_cryptseen		(vTHX->Icryptseen)
#define PL_cshlen		(vTHX->Icshlen)
#define PL_cshname		(vTHX->Icshname)
#define PL_curcopdb		(vTHX->Icurcopdb)
#define PL_curstname		(vTHX->Icurstname)
#define PL_custom_op_descs	(vTHX->Icustom_op_descs)
#define PL_custom_op_names	(vTHX->Icustom_op_names)
#define PL_cv_has_eval		(vTHX->Icv_has_eval)
#define PL_dbargs		(vTHX->Idbargs)
#define PL_debstash		(vTHX->Idebstash)
#define PL_debug		(vTHX->Idebug)
#define PL_debug_pad		(vTHX->Idebug_pad)
#define PL_def_layerlist	(vTHX->Idef_layerlist)
#define PL_defgv		(vTHX->Idefgv)
#define PL_diehook		(vTHX->Idiehook)
#define PL_doextract		(vTHX->Idoextract)
#define PL_doswitches		(vTHX->Idoswitches)
#define PL_dowarn		(vTHX->Idowarn)
#define PL_dumper_fd		(vTHX->Idumper_fd)
#define PL_e_script		(vTHX->Ie_script)
#define PL_egid			(vTHX->Iegid)
#define PL_encoding		(vTHX->Iencoding)
#define PL_endav		(vTHX->Iendav)
#define PL_envgv		(vTHX->Ienvgv)
#define PL_errgv		(vTHX->Ierrgv)
#define PL_error_count		(vTHX->Ierror_count)
#define PL_euid			(vTHX->Ieuid)
#define PL_eval_root		(vTHX->Ieval_root)
#define PL_eval_start		(vTHX->Ieval_start)
#define PL_evalseq		(vTHX->Ievalseq)
#define PL_exit_flags		(vTHX->Iexit_flags)
#define PL_exitlist		(vTHX->Iexitlist)
#define PL_exitlistlen		(vTHX->Iexitlistlen)
#define PL_expect		(vTHX->Iexpect)
#define PL_fdpid		(vTHX->Ifdpid)
#define PL_fdscript		(vTHX->Ifdscript)
#define PL_filemode		(vTHX->Ifilemode)
#define PL_forkprocess		(vTHX->Iforkprocess)
#define PL_formfeed		(vTHX->Iformfeed)
#define PL_generation		(vTHX->Igeneration)
#define PL_gensym		(vTHX->Igensym)
#define PL_gid			(vTHX->Igid)
#define PL_glob_index		(vTHX->Iglob_index)
#define PL_globalstash		(vTHX->Iglobalstash)
#define PL_hash_seed		(vTHX->Ihash_seed)
#define PL_hash_seed_set	(vTHX->Ihash_seed_set)
#define PL_hintgv		(vTHX->Ihintgv)
#define PL_hints		(vTHX->Ihints)
#define PL_in_clean_all		(vTHX->Iin_clean_all)
#define PL_in_clean_objs	(vTHX->Iin_clean_objs)
#define PL_in_load_module	(vTHX->Iin_load_module)
#define PL_in_my		(vTHX->Iin_my)
#define PL_in_my_stash		(vTHX->Iin_my_stash)
#define PL_incgv		(vTHX->Iincgv)
#define PL_initav		(vTHX->Iinitav)
#define PL_inplace		(vTHX->Iinplace)
#define PL_known_layers		(vTHX->Iknown_layers)
#define PL_last_lop		(vTHX->Ilast_lop)
#define PL_last_lop_op		(vTHX->Ilast_lop_op)
#define PL_last_swash_hv	(vTHX->Ilast_swash_hv)
#define PL_last_swash_key	(vTHX->Ilast_swash_key)
#define PL_last_swash_klen	(vTHX->Ilast_swash_klen)
#define PL_last_swash_slen	(vTHX->Ilast_swash_slen)
#define PL_last_swash_tmps	(vTHX->Ilast_swash_tmps)
#define PL_last_uni		(vTHX->Ilast_uni)
#define PL_lastfd		(vTHX->Ilastfd)
#define PL_laststatval		(vTHX->Ilaststatval)
#define PL_laststype		(vTHX->Ilaststype)
#define PL_lex_brackets		(vTHX->Ilex_brackets)
#define PL_lex_brackstack	(vTHX->Ilex_brackstack)
#define PL_lex_casemods		(vTHX->Ilex_casemods)
#define PL_lex_casestack	(vTHX->Ilex_casestack)
#define PL_lex_defer		(vTHX->Ilex_defer)
#define PL_lex_dojoin		(vTHX->Ilex_dojoin)
#define PL_lex_expect		(vTHX->Ilex_expect)
#define PL_lex_formbrack	(vTHX->Ilex_formbrack)
#define PL_lex_inpat		(vTHX->Ilex_inpat)
#define PL_lex_inwhat		(vTHX->Ilex_inwhat)
#define PL_lex_op		(vTHX->Ilex_op)
#define PL_lex_repl		(vTHX->Ilex_repl)
#define PL_lex_starts		(vTHX->Ilex_starts)
#define PL_lex_state		(vTHX->Ilex_state)
#define PL_lex_stuff		(vTHX->Ilex_stuff)
#define PL_lineary		(vTHX->Ilineary)
#define PL_linestart		(vTHX->Ilinestart)
#define PL_linestr		(vTHX->Ilinestr)
#define PL_localpatches		(vTHX->Ilocalpatches)
#define PL_lockhook		(vTHX->Ilockhook)
#define PL_main_cv		(vTHX->Imain_cv)
#define PL_main_root		(vTHX->Imain_root)
#define PL_main_start		(vTHX->Imain_start)
#define PL_max_intro_pending	(vTHX->Imax_intro_pending)
#define PL_maxo			(vTHX->Imaxo)
#define PL_maxsysfd		(vTHX->Imaxsysfd)
#define PL_mess_sv		(vTHX->Imess_sv)
#define PL_min_intro_pending	(vTHX->Imin_intro_pending)
#define PL_minus_E		(vTHX->Iminus_E)
#define PL_minus_F		(vTHX->Iminus_F)
#define PL_minus_a		(vTHX->Iminus_a)
#define PL_minus_c		(vTHX->Iminus_c)
#define PL_minus_l		(vTHX->Iminus_l)
#define PL_minus_n		(vTHX->Iminus_n)
#define PL_minus_p		(vTHX->Iminus_p)
#define PL_modglobal		(vTHX->Imodglobal)
#define PL_multi_close		(vTHX->Imulti_close)
#define PL_multi_end		(vTHX->Imulti_end)
#define PL_multi_open		(vTHX->Imulti_open)
#define PL_multi_start		(vTHX->Imulti_start)
#define PL_multiline		(vTHX->Imultiline)
#define PL_my_cxt_list		(vTHX->Imy_cxt_list)
#define PL_my_cxt_size		(vTHX->Imy_cxt_size)
#define PL_nexttoke		(vTHX->Inexttoke)
#define PL_nexttype		(vTHX->Inexttype)
#define PL_nextval		(vTHX->Inextval)
#define PL_nice_chunk		(vTHX->Inice_chunk)
#define PL_nice_chunk_size	(vTHX->Inice_chunk_size)
#define PL_nomemok		(vTHX->Inomemok)
#define PL_numeric_compat1	(vTHX->Inumeric_compat1)
#define PL_numeric_local	(vTHX->Inumeric_local)
#define PL_numeric_name		(vTHX->Inumeric_name)
#define PL_numeric_radix_sv	(vTHX->Inumeric_radix_sv)
#define PL_numeric_standard	(vTHX->Inumeric_standard)
#define PL_oldbufptr		(vTHX->Ioldbufptr)
#define PL_oldname		(vTHX->Ioldname)
#define PL_oldoldbufptr		(vTHX->Ioldoldbufptr)
#define PL_op_mask		(vTHX->Iop_mask)
#define PL_origalen		(vTHX->Iorigalen)
#define PL_origargc		(vTHX->Iorigargc)
#define PL_origargv		(vTHX->Iorigargv)
#define PL_origenviron		(vTHX->Iorigenviron)
#define PL_origfilename		(vTHX->Iorigfilename)
#define PL_ors_sv		(vTHX->Iors_sv)
#define PL_osname		(vTHX->Iosname)
#define PL_pad_reset_pending	(vTHX->Ipad_reset_pending)
#define PL_padix		(vTHX->Ipadix)
#define PL_padix_floor		(vTHX->Ipadix_floor)
#define PL_patchlevel		(vTHX->Ipatchlevel)
#define PL_pending_ident	(vTHX->Ipending_ident)
#define PL_perl_destruct_level	(vTHX->Iperl_destruct_level)
#define PL_perldb		(vTHX->Iperldb)
#define PL_perlio		(vTHX->Iperlio)
#define PL_pidstatus		(vTHX->Ipidstatus)
#define PL_ppid			(vTHX->Ippid)
#define PL_preambleav		(vTHX->Ipreambleav)
#define PL_preambled		(vTHX->Ipreambled)
#define PL_preprocess		(vTHX->Ipreprocess)
#define PL_profiledata		(vTHX->Iprofiledata)
#define PL_psig_name		(vTHX->Ipsig_name)
#define PL_psig_pend		(vTHX->Ipsig_pend)
#define PL_psig_ptr		(vTHX->Ipsig_ptr)
#define PL_ptr_table		(vTHX->Iptr_table)
#define PL_reentrant_buffer	(vTHX->Ireentrant_buffer)
#define PL_reentrant_retint	(vTHX->Ireentrant_retint)
#define PL_regex_pad		(vTHX->Iregex_pad)
#define PL_regex_padav		(vTHX->Iregex_padav)
#define PL_rehash_seed		(vTHX->Irehash_seed)
#define PL_rehash_seed_set	(vTHX->Irehash_seed_set)
#define PL_replgv		(vTHX->Ireplgv)
#define PL_rsfp			(vTHX->Irsfp)
#define PL_rsfp_filters		(vTHX->Irsfp_filters)
#define PL_runops		(vTHX->Irunops)
#define PL_runops_dbg		(vTHX->Irunops_dbg)
#define PL_runops_std		(vTHX->Irunops_std)
#define PL_savebegin		(vTHX->Isavebegin)
#define PL_sawampersand		(vTHX->Isawampersand)
#define PL_sharehook		(vTHX->Isharehook)
#define PL_sig_pending		(vTHX->Isig_pending)
#define PL_sighandlerp		(vTHX->Isighandlerp)
#define PL_signals		(vTHX->Isignals)
#define PL_sort_RealCmp		(vTHX->Isort_RealCmp)
#define PL_splitstr		(vTHX->Isplitstr)
#define PL_srand_called		(vTHX->Isrand_called)
#define PL_stashcache		(vTHX->Istashcache)
#define PL_statusvalue		(vTHX->Istatusvalue)
#define PL_statusvalue_posix	(vTHX->Istatusvalue_posix)
#define PL_statusvalue_vms	(vTHX->Istatusvalue_vms)
#define PL_stderrgv		(vTHX->Istderrgv)
#define PL_stdingv		(vTHX->Istdingv)
#define PL_strtab		(vTHX->Istrtab)
#define PL_sub_generation	(vTHX->Isub_generation)
#define PL_sublex_info		(vTHX->Isublex_info)
#define PL_subline		(vTHX->Isubline)
#define PL_subname		(vTHX->Isubname)
#define PL_suidscript		(vTHX->Isuidscript)
#define PL_sv_arenaroot		(vTHX->Isv_arenaroot)
#define PL_sv_count		(vTHX->Isv_count)
#define PL_sv_no		(vTHX->Isv_no)
#define PL_sv_objcount		(vTHX->Isv_objcount)
#define PL_sv_root		(vTHX->Isv_root)
#define PL_sv_undef		(vTHX->Isv_undef)
#define PL_sv_yes		(vTHX->Isv_yes)
#define PL_sys_intern		(vTHX->Isys_intern)
#define PL_taint_warn		(vTHX->Itaint_warn)
#define PL_tainting		(vTHX->Itainting)
#define PL_threadhook		(vTHX->Ithreadhook)
#define PL_tokenbuf		(vTHX->Itokenbuf)
#define PL_uid			(vTHX->Iuid)
#define PL_unicode		(vTHX->Iunicode)
#define PL_unlockhook		(vTHX->Iunlockhook)
#define PL_unsafe		(vTHX->Iunsafe)
#define PL_utf8_alnum		(vTHX->Iutf8_alnum)
#define PL_utf8_alnumc		(vTHX->Iutf8_alnumc)
#define PL_utf8_alpha		(vTHX->Iutf8_alpha)
#define PL_utf8_ascii		(vTHX->Iutf8_ascii)
#define PL_utf8_cntrl		(vTHX->Iutf8_cntrl)
#define PL_utf8_digit		(vTHX->Iutf8_digit)
#define PL_utf8_graph		(vTHX->Iutf8_graph)
#define PL_utf8_idcont		(vTHX->Iutf8_idcont)
#define PL_utf8_idstart		(vTHX->Iutf8_idstart)
#define PL_utf8_lower		(vTHX->Iutf8_lower)
#define PL_utf8_mark		(vTHX->Iutf8_mark)
#define PL_utf8_print		(vTHX->Iutf8_print)
#define PL_utf8_punct		(vTHX->Iutf8_punct)
#define PL_utf8_space		(vTHX->Iutf8_space)
#define PL_utf8_tofold		(vTHX->Iutf8_tofold)
#define PL_utf8_tolower		(vTHX->Iutf8_tolower)
#define PL_utf8_totitle		(vTHX->Iutf8_totitle)
#define PL_utf8_toupper		(vTHX->Iutf8_toupper)
#define PL_utf8_upper		(vTHX->Iutf8_upper)
#define PL_utf8_xdigit		(vTHX->Iutf8_xdigit)
#define PL_utf8locale		(vTHX->Iutf8locale)
#define PL_uudmap		(vTHX->Iuudmap)
#define PL_warnhook		(vTHX->Iwarnhook)
#define PL_widesyscalls		(vTHX->Iwidesyscalls)
#define PL_yycharp		(vTHX->Iyycharp)
#define PL_yylvalp		(vTHX->Iyylvalp)

#else	/* !MULTIPLICITY */

/* case 1 above */

#define PL_IArgv		PL_Argv
#define PL_ICmd			PL_Cmd
#define PL_IDBassertion		PL_DBassertion
#define PL_IDBcv		PL_DBcv
#define PL_IDBgv		PL_DBgv
#define PL_IDBline		PL_DBline
#define PL_IDBsignal		PL_DBsignal
#define PL_IDBsingle		PL_DBsingle
#define PL_IDBsub		PL_DBsub
#define PL_IDBtrace		PL_DBtrace
#define PL_IDir			PL_Dir
#define PL_IEnv			PL_Env
#define PL_ILIO			PL_LIO
#define PL_IMem			PL_Mem
#define PL_IMemParse		PL_MemParse
#define PL_IMemShared		PL_MemShared
#define PL_IOpPtr		PL_OpPtr
#define PL_IOpSlab		PL_OpSlab
#define PL_IOpSpace		PL_OpSpace
#define PL_IProc		PL_Proc
#define PL_ISock		PL_Sock
#define PL_IStdIO		PL_StdIO
#define PL_Iamagic_generation	PL_amagic_generation
#define PL_Ian			PL_an
#define PL_Iargvgv		PL_argvgv
#define PL_Iargvout_stack	PL_argvout_stack
#define PL_Iargvoutgv		PL_argvoutgv
#define PL_Ibasetime		PL_basetime
#define PL_Ibeginav		PL_beginav
#define PL_Ibeginav_save	PL_beginav_save
#define PL_Ibitcount		PL_bitcount
#define PL_Ibody_arenaroots	PL_body_arenaroots
#define PL_Ibody_roots		PL_body_roots
#define PL_Ibufend		PL_bufend
#define PL_Ibufptr		PL_bufptr
#define PL_Icheckav		PL_checkav
#define PL_Icheckav_save	PL_checkav_save
#define PL_Iclocktick		PL_clocktick
#define PL_Icollation_ix	PL_collation_ix
#define PL_Icollation_name	PL_collation_name
#define PL_Icollation_standard	PL_collation_standard
#define PL_Icollxfrm_base	PL_collxfrm_base
#define PL_Icollxfrm_mult	PL_collxfrm_mult
#define PL_Icompcv		PL_compcv
#define PL_Icompiling		PL_compiling
#define PL_Icomppad		PL_comppad
#define PL_Icomppad_name	PL_comppad_name
#define PL_Icomppad_name_fill	PL_comppad_name_fill
#define PL_Icomppad_name_floor	PL_comppad_name_floor
#define PL_Icop_seqmax		PL_cop_seqmax
#define PL_Icopline		PL_copline
#define PL_Icryptseen		PL_cryptseen
#define PL_Icshlen		PL_cshlen
#define PL_Icshname		PL_cshname
#define PL_Icurcopdb		PL_curcopdb
#define PL_Icurstname		PL_curstname
#define PL_Icustom_op_descs	PL_custom_op_descs
#define PL_Icustom_op_names	PL_custom_op_names
#define PL_Icv_has_eval		PL_cv_has_eval
#define PL_Idbargs		PL_dbargs
#define PL_Idebstash		PL_debstash
#define PL_Idebug		PL_debug
#define PL_Idebug_pad		PL_debug_pad
#define PL_Idef_layerlist	PL_def_layerlist
#define PL_Idefgv		PL_defgv
#define PL_Idiehook		PL_diehook
#define PL_Idoextract		PL_doextract
#define PL_Idoswitches		PL_doswitches
#define PL_Idowarn		PL_dowarn
#define PL_Idumper_fd		PL_dumper_fd
#define PL_Ie_script		PL_e_script
#define PL_Iegid		PL_egid
#define PL_Iencoding		PL_encoding
#define PL_Iendav		PL_endav
#define PL_Ienvgv		PL_envgv
#define PL_Ierrgv		PL_errgv
#define PL_Ierror_count		PL_error_count
#define PL_Ieuid		PL_euid
#define PL_Ieval_root		PL_eval_root
#define PL_Ieval_start		PL_eval_start
#define PL_Ievalseq		PL_evalseq
#define PL_Iexit_flags		PL_exit_flags
#define PL_Iexitlist		PL_exitlist
#define PL_Iexitlistlen		PL_exitlistlen
#define PL_Iexpect		PL_expect
#define PL_Ifdpid		PL_fdpid
#define PL_Ifdscript		PL_fdscript
#define PL_Ifilemode		PL_filemode
#define PL_Iforkprocess		PL_forkprocess
#define PL_Iformfeed		PL_formfeed
#define PL_Igeneration		PL_generation
#define PL_Igensym		PL_gensym
#define PL_Igid			PL_gid
#define PL_Iglob_index		PL_glob_index
#define PL_Iglobalstash		PL_globalstash
#define PL_Ihash_seed		PL_hash_seed
#define PL_Ihash_seed_set	PL_hash_seed_set
#define PL_Ihintgv		PL_hintgv
#define PL_Ihints		PL_hints
#define PL_Iin_clean_all	PL_in_clean_all
#define PL_Iin_clean_objs	PL_in_clean_objs
#define PL_Iin_load_module	PL_in_load_module
#define PL_Iin_my		PL_in_my
#define PL_Iin_my_stash		PL_in_my_stash
#define PL_Iincgv		PL_incgv
#define PL_Iinitav		PL_initav
#define PL_Iinplace		PL_inplace
#define PL_Iknown_layers	PL_known_layers
#define PL_Ilast_lop		PL_last_lop
#define PL_Ilast_lop_op		PL_last_lop_op
#define PL_Ilast_swash_hv	PL_last_swash_hv
#define PL_Ilast_swash_key	PL_last_swash_key
#define PL_Ilast_swash_klen	PL_last_swash_klen
#define PL_Ilast_swash_slen	PL_last_swash_slen
#define PL_Ilast_swash_tmps	PL_last_swash_tmps
#define PL_Ilast_uni		PL_last_uni
#define PL_Ilastfd		PL_lastfd
#define PL_Ilaststatval		PL_laststatval
#define PL_Ilaststype		PL_laststype
#define PL_Ilex_brackets	PL_lex_brackets
#define PL_Ilex_brackstack	PL_lex_brackstack
#define PL_Ilex_casemods	PL_lex_casemods
#define PL_Ilex_casestack	PL_lex_casestack
#define PL_Ilex_defer		PL_lex_defer
#define PL_Ilex_dojoin		PL_lex_dojoin
#define PL_Ilex_expect		PL_lex_expect
#define PL_Ilex_formbrack	PL_lex_formbrack
#define PL_Ilex_inpat		PL_lex_inpat
#define PL_Ilex_inwhat		PL_lex_inwhat
#define PL_Ilex_op		PL_lex_op
#define PL_Ilex_repl		PL_lex_repl
#define PL_Ilex_starts		PL_lex_starts
#define PL_Ilex_state		PL_lex_state
#define PL_Ilex_stuff		PL_lex_stuff
#define PL_Ilineary		PL_lineary
#define PL_Ilinestart		PL_linestart
#define PL_Ilinestr		PL_linestr
#define PL_Ilocalpatches	PL_localpatches
#define PL_Ilockhook		PL_lockhook
#define PL_Imain_cv		PL_main_cv
#define PL_Imain_root		PL_main_root
#define PL_Imain_start		PL_main_start
#define PL_Imax_intro_pending	PL_max_intro_pending
#define PL_Imaxo		PL_maxo
#define PL_Imaxsysfd		PL_maxsysfd
#define PL_Imess_sv		PL_mess_sv
#define PL_Imin_intro_pending	PL_min_intro_pending
#define PL_Iminus_E		PL_minus_E
#define PL_Iminus_F		PL_minus_F
#define PL_Iminus_a		PL_minus_a
#define PL_Iminus_c		PL_minus_c
#define PL_Iminus_l		PL_minus_l
#define PL_Iminus_n		PL_minus_n
#define PL_Iminus_p		PL_minus_p
#define PL_Imodglobal		PL_modglobal
#define PL_Imulti_close		PL_multi_close
#define PL_Imulti_end		PL_multi_end
#define PL_Imulti_open		PL_multi_open
#define PL_Imulti_start		PL_multi_start
#define PL_Imultiline		PL_multiline
#define PL_Imy_cxt_list		PL_my_cxt_list
#define PL_Imy_cxt_size		PL_my_cxt_size
#define PL_Inexttoke		PL_nexttoke
#define PL_Inexttype		PL_nexttype
#define PL_Inextval		PL_nextval
#define PL_Inice_chunk		PL_nice_chunk
#define PL_Inice_chunk_size	PL_nice_chunk_size
#define PL_Inomemok		PL_nomemok
#define PL_Inumeric_compat1	PL_numeric_compat1
#define PL_Inumeric_local	PL_numeric_local
#define PL_Inumeric_name	PL_numeric_name
#define PL_Inumeric_radix_sv	PL_numeric_radix_sv
#define PL_Inumeric_standard	PL_numeric_standard
#define PL_Ioldbufptr		PL_oldbufptr
#define PL_Ioldname		PL_oldname
#define PL_Ioldoldbufptr	PL_oldoldbufptr
#define PL_Iop_mask		PL_op_mask
#define PL_Iorigalen		PL_origalen
#define PL_Iorigargc		PL_origargc
#define PL_Iorigargv		PL_origargv
#define PL_Iorigenviron		PL_origenviron
#define PL_Iorigfilename	PL_origfilename
#define PL_Iors_sv		PL_ors_sv
#define PL_Iosname		PL_osname
#define PL_Ipad_reset_pending	PL_pad_reset_pending
#define PL_Ipadix		PL_padix
#define PL_Ipadix_floor		PL_padix_floor
#define PL_Ipatchlevel		PL_patchlevel
#define PL_Ipending_ident	PL_pending_ident
#define PL_Iperl_destruct_level	PL_perl_destruct_level
#define PL_Iperldb		PL_perldb
#define PL_Iperlio		PL_perlio
#define PL_Ipidstatus		PL_pidstatus
#define PL_Ippid		PL_ppid
#define PL_Ipreambleav		PL_preambleav
#define PL_Ipreambled		PL_preambled
#define PL_Ipreprocess		PL_preprocess
#define PL_Iprofiledata		PL_profiledata
#define PL_Ipsig_name		PL_psig_name
#define PL_Ipsig_pend		PL_psig_pend
#define PL_Ipsig_ptr		PL_psig_ptr
#define PL_Iptr_table		PL_ptr_table
#define PL_Ireentrant_buffer	PL_reentrant_buffer
#define PL_Ireentrant_retint	PL_reentrant_retint
#define PL_Iregex_pad		PL_regex_pad
#define PL_Iregex_padav		PL_regex_padav
#define PL_Irehash_seed		PL_rehash_seed
#define PL_Irehash_seed_set	PL_rehash_seed_set
#define PL_Ireplgv		PL_replgv
#define PL_Irsfp		PL_rsfp
#define PL_Irsfp_filters	PL_rsfp_filters
#define PL_Irunops		PL_runops
#define PL_Irunops_dbg		PL_runops_dbg
#define PL_Irunops_std		PL_runops_std
#define PL_Isavebegin		PL_savebegin
#define PL_Isawampersand	PL_sawampersand
#define PL_Isharehook		PL_sharehook
#define PL_Isig_pending		PL_sig_pending
#define PL_Isighandlerp		PL_sighandlerp
#define PL_Isignals		PL_signals
#define PL_Isort_RealCmp	PL_sort_RealCmp
#define PL_Isplitstr		PL_splitstr
#define PL_Isrand_called	PL_srand_called
#define PL_Istashcache		PL_stashcache
#define PL_Istatusvalue		PL_statusvalue
#define PL_Istatusvalue_posix	PL_statusvalue_posix
#define PL_Istatusvalue_vms	PL_statusvalue_vms
#define PL_Istderrgv		PL_stderrgv
#define PL_Istdingv		PL_stdingv
#define PL_Istrtab		PL_strtab
#define PL_Isub_generation	PL_sub_generation
#define PL_Isublex_info		PL_sublex_info
#define PL_Isubline		PL_subline
#define PL_Isubname		PL_subname
#define PL_Isuidscript		PL_suidscript
#define PL_Isv_arenaroot	PL_sv_arenaroot
#define PL_Isv_count		PL_sv_count
#define PL_Isv_no		PL_sv_no
#define PL_Isv_objcount		PL_sv_objcount
#define PL_Isv_root		PL_sv_root
#define PL_Isv_undef		PL_sv_undef
#define PL_Isv_yes		PL_sv_yes
#define PL_Isys_intern		PL_sys_intern
#define PL_Itaint_warn		PL_taint_warn
#define PL_Itainting		PL_tainting
#define PL_Ithreadhook		PL_threadhook
#define PL_Itokenbuf		PL_tokenbuf
#define PL_Iuid			PL_uid
#define PL_Iunicode		PL_unicode
#define PL_Iunlockhook		PL_unlockhook
#define PL_Iunsafe		PL_unsafe
#define PL_Iutf8_alnum		PL_utf8_alnum
#define PL_Iutf8_alnumc		PL_utf8_alnumc
#define PL_Iutf8_alpha		PL_utf8_alpha
#define PL_Iutf8_ascii		PL_utf8_ascii
#define PL_Iutf8_cntrl		PL_utf8_cntrl
#define PL_Iutf8_digit		PL_utf8_digit
#define PL_Iutf8_graph		PL_utf8_graph
#define PL_Iutf8_idcont		PL_utf8_idcont
#define PL_Iutf8_idstart	PL_utf8_idstart
#define PL_Iutf8_lower		PL_utf8_lower
#define PL_Iutf8_mark		PL_utf8_mark
#define PL_Iutf8_print		PL_utf8_print
#define PL_Iutf8_punct		PL_utf8_punct
#define PL_Iutf8_space		PL_utf8_space
#define PL_Iutf8_tofold		PL_utf8_tofold
#define PL_Iutf8_tolower	PL_utf8_tolower
#define PL_Iutf8_totitle	PL_utf8_totitle
#define PL_Iutf8_toupper	PL_utf8_toupper
#define PL_Iutf8_upper		PL_utf8_upper
#define PL_Iutf8_xdigit		PL_utf8_xdigit
#define PL_Iutf8locale		PL_utf8locale
#define PL_Iuudmap		PL_uudmap
#define PL_Iwarnhook		PL_warnhook
#define PL_Iwidesyscalls	PL_widesyscalls
#define PL_Iyycharp		PL_yycharp
#define PL_Iyylvalp		PL_yylvalp

#define PL_TSv			PL_Sv
#define PL_TXpv			PL_Xpv
#define PL_Tav_fetch_sv		PL_av_fetch_sv
#define PL_Tbodytarget		PL_bodytarget
#define PL_Tbostr		PL_bostr
#define PL_Tchopset		PL_chopset
#define PL_Tcolors		PL_colors
#define PL_Tcolorset		PL_colorset
#define PL_Tcurcop		PL_curcop
#define PL_Tcurpad		PL_curpad
#define PL_Tcurpm		PL_curpm
#define PL_Tcurstack		PL_curstack
#define PL_Tcurstackinfo	PL_curstackinfo
#define PL_Tcurstash		PL_curstash
#define PL_Tdefoutgv		PL_defoutgv
#define PL_Tdefstash		PL_defstash
#define PL_Tdelaymagic		PL_delaymagic
#define PL_Tdirty		PL_dirty
#define PL_Tdumpindent		PL_dumpindent
#define PL_Tefloatbuf		PL_efloatbuf
#define PL_Tefloatsize		PL_efloatsize
#define PL_Terrors		PL_errors
#define PL_Tfirstgv		PL_firstgv
#define PL_Tformtarget		PL_formtarget
#define PL_Thv_fetch_ent_mh	PL_hv_fetch_ent_mh
#define PL_Thv_fetch_sv		PL_hv_fetch_sv
#define PL_Tin_eval		PL_in_eval
#define PL_Tlast_in_gv		PL_last_in_gv
#define PL_Tlastgotoprobe	PL_lastgotoprobe
#define PL_Tlastscream		PL_lastscream
#define PL_Tlocalizing		PL_localizing
#define PL_Tmainstack		PL_mainstack
#define PL_Tmarkstack		PL_markstack
#define PL_Tmarkstack_max	PL_markstack_max
#define PL_Tmarkstack_ptr	PL_markstack_ptr
#define PL_Tmaxscream		PL_maxscream
#define PL_Tmodcount		PL_modcount
#define PL_Tna			PL_na
#define PL_Tnrs			PL_nrs
#define PL_Tofs_sv		PL_ofs_sv
#define PL_Top			PL_op
#define PL_Topsave		PL_opsave
#define PL_Tpeepp		PL_peepp
#define PL_Treg_call_cc		PL_reg_call_cc
#define PL_Treg_curpm		PL_reg_curpm
#define PL_Treg_eval_set	PL_reg_eval_set
#define PL_Treg_flags		PL_reg_flags
#define PL_Treg_ganch		PL_reg_ganch
#define PL_Treg_leftiter	PL_reg_leftiter
#define PL_Treg_magic		PL_reg_magic
#define PL_Treg_match_utf8	PL_reg_match_utf8
#define PL_Treg_maxiter		PL_reg_maxiter
#define PL_Treg_oldcurpm	PL_reg_oldcurpm
#define PL_Treg_oldpos		PL_reg_oldpos
#define PL_Treg_oldsaved	PL_reg_oldsaved
#define PL_Treg_oldsavedlen	PL_reg_oldsavedlen
#define PL_Treg_poscache	PL_reg_poscache
#define PL_Treg_poscache_size	PL_reg_poscache_size
#define PL_Treg_re		PL_reg_re
#define PL_Treg_start_tmp	PL_reg_start_tmp
#define PL_Treg_start_tmpl	PL_reg_start_tmpl
#define PL_Treg_starttry	PL_reg_starttry
#define PL_Treg_sv		PL_reg_sv
#define PL_Tregbol		PL_regbol
#define PL_Tregcc		PL_regcc
#define PL_Tregcompp		PL_regcompp
#define PL_Tregdata		PL_regdata
#define PL_Tregdummy		PL_regdummy
#define PL_Tregendp		PL_regendp
#define PL_Tregeol		PL_regeol
#define PL_Tregexecp		PL_regexecp
#define PL_Tregfree		PL_regfree
#define PL_Tregindent		PL_regindent
#define PL_Treginput		PL_reginput
#define PL_Tregint_start	PL_regint_start
#define PL_Tregint_string	PL_regint_string
#define PL_Treginterp_cnt	PL_reginterp_cnt
#define PL_Treglastcloseparen	PL_reglastcloseparen
#define PL_Treglastparen	PL_reglastparen
#define PL_Tregnarrate		PL_regnarrate
#define PL_Tregnpar		PL_regnpar
#define PL_Tregprecomp		PL_regprecomp
#define PL_Tregprogram		PL_regprogram
#define PL_Tregsize		PL_regsize
#define PL_Tregstartp		PL_regstartp
#define PL_Tregtill		PL_regtill
#define PL_Trestartop		PL_restartop
#define PL_Trs			PL_rs
#define PL_Tsavestack		PL_savestack
#define PL_Tsavestack_ix	PL_savestack_ix
#define PL_Tsavestack_max	PL_savestack_max
#define PL_Tscopestack		PL_scopestack
#define PL_Tscopestack_ix	PL_scopestack_ix
#define PL_Tscopestack_max	PL_scopestack_max
#define PL_Tscreamfirst		PL_screamfirst
#define PL_Tscreamnext		PL_screamnext
#define PL_Tsecondgv		PL_secondgv
#define PL_Tsortcop		PL_sortcop
#define PL_Tsortstash		PL_sortstash
#define PL_Tstack_base		PL_stack_base
#define PL_Tstack_max		PL_stack_max
#define PL_Tstack_sp		PL_stack_sp
#define PL_Tstart_env		PL_start_env
#define PL_Tstatbuf		PL_statbuf
#define PL_Tstatcache		PL_statcache
#define PL_Tstatgv		PL_statgv
#define PL_Tstatname		PL_statname
#define PL_Ttainted		PL_tainted
#define PL_Ttimesbuf		PL_timesbuf
#define PL_Ttmps_floor		PL_tmps_floor
#define PL_Ttmps_ix		PL_tmps_ix
#define PL_Ttmps_max		PL_tmps_max
#define PL_Ttmps_stack		PL_tmps_stack
#define PL_Ttop_env		PL_top_env
#define PL_Ttoptarget		PL_toptarget
#define PL_Twatchaddr		PL_watchaddr
#define PL_Twatchok		PL_watchok

#endif	/* MULTIPLICITY */

#if defined(PERL_GLOBAL_STRUCT)

#define PL_No			(my_vars->GNo)
#define PL_GNo			(my_vars->GNo)
#define PL_Yes			(my_vars->GYes)
#define PL_GYes			(my_vars->GYes)
#define PL_appctx		(my_vars->Gappctx)
#define PL_Gappctx		(my_vars->Gappctx)
#define PL_check		(my_vars->Gcheck)
#define PL_Gcheck		(my_vars->Gcheck)
#define PL_csighandlerp		(my_vars->Gcsighandlerp)
#define PL_Gcsighandlerp	(my_vars->Gcsighandlerp)
#define PL_curinterp		(my_vars->Gcurinterp)
#define PL_Gcurinterp		(my_vars->Gcurinterp)
#define PL_do_undump		(my_vars->Gdo_undump)
#define PL_Gdo_undump		(my_vars->Gdo_undump)
#define PL_dollarzero_mutex	(my_vars->Gdollarzero_mutex)
#define PL_Gdollarzero_mutex	(my_vars->Gdollarzero_mutex)
#define PL_fold_locale		(my_vars->Gfold_locale)
#define PL_Gfold_locale		(my_vars->Gfold_locale)
#define PL_hexdigit		(my_vars->Ghexdigit)
#define PL_Ghexdigit		(my_vars->Ghexdigit)
#define PL_malloc_mutex		(my_vars->Gmalloc_mutex)
#define PL_Gmalloc_mutex	(my_vars->Gmalloc_mutex)
#define PL_mmap_page_size	(my_vars->Gmmap_page_size)
#define PL_Gmmap_page_size	(my_vars->Gmmap_page_size)
#define PL_my_ctx_mutex		(my_vars->Gmy_ctx_mutex)
#define PL_Gmy_ctx_mutex	(my_vars->Gmy_ctx_mutex)
#define PL_my_cxt_index		(my_vars->Gmy_cxt_index)
#define PL_Gmy_cxt_index	(my_vars->Gmy_cxt_index)
#define PL_op_mutex		(my_vars->Gop_mutex)
#define PL_Gop_mutex		(my_vars->Gop_mutex)
#define PL_op_seq		(my_vars->Gop_seq)
#define PL_Gop_seq		(my_vars->Gop_seq)
#define PL_op_sequence		(my_vars->Gop_sequence)
#define PL_Gop_sequence		(my_vars->Gop_sequence)
#define PL_patleave		(my_vars->Gpatleave)
#define PL_Gpatleave		(my_vars->Gpatleave)
#define PL_perlio_debug_fd	(my_vars->Gperlio_debug_fd)
#define PL_Gperlio_debug_fd	(my_vars->Gperlio_debug_fd)
#define PL_perlio_fd_refcnt	(my_vars->Gperlio_fd_refcnt)
#define PL_Gperlio_fd_refcnt	(my_vars->Gperlio_fd_refcnt)
#define PL_ppaddr		(my_vars->Gppaddr)
#define PL_Gppaddr		(my_vars->Gppaddr)
#define PL_sh_path		(my_vars->Gsh_path)
#define PL_Gsh_path		(my_vars->Gsh_path)
#define PL_sig_defaulting	(my_vars->Gsig_defaulting)
#define PL_Gsig_defaulting	(my_vars->Gsig_defaulting)
#define PL_sig_handlers_initted	(my_vars->Gsig_handlers_initted)
#define PL_Gsig_handlers_initted	(my_vars->Gsig_handlers_initted)
#define PL_sig_ignoring		(my_vars->Gsig_ignoring)
#define PL_Gsig_ignoring	(my_vars->Gsig_ignoring)
#define PL_sig_sv		(my_vars->Gsig_sv)
#define PL_Gsig_sv		(my_vars->Gsig_sv)
#define PL_sig_trapped		(my_vars->Gsig_trapped)
#define PL_Gsig_trapped		(my_vars->Gsig_trapped)
#define PL_sigfpe_saved		(my_vars->Gsigfpe_saved)
#define PL_Gsigfpe_saved	(my_vars->Gsigfpe_saved)
#define PL_sv_placeholder	(my_vars->Gsv_placeholder)
#define PL_Gsv_placeholder	(my_vars->Gsv_placeholder)
#define PL_thr_key		(my_vars->Gthr_key)
#define PL_Gthr_key		(my_vars->Gthr_key)
#define PL_timesbase		(my_vars->Gtimesbase)
#define PL_Gtimesbase		(my_vars->Gtimesbase)
#define PL_use_safe_putenv	(my_vars->Guse_safe_putenv)
#define PL_Guse_safe_putenv	(my_vars->Guse_safe_putenv)
#define PL_watch_pvx		(my_vars->Gwatch_pvx)
#define PL_Gwatch_pvx		(my_vars->Gwatch_pvx)

#else /* !PERL_GLOBAL_STRUCT */

#define PL_GNo			PL_No
#define PL_GYes			PL_Yes
#define PL_Gappctx		PL_appctx
#define PL_Gcheck		PL_check
#define PL_Gcsighandlerp	PL_csighandlerp
#define PL_Gcurinterp		PL_curinterp
#define PL_Gdo_undump		PL_do_undump
#define PL_Gdollarzero_mutex	PL_dollarzero_mutex
#define PL_Gfold_locale		PL_fold_locale
#define PL_Ghexdigit		PL_hexdigit
#define PL_Gmalloc_mutex	PL_malloc_mutex
#define PL_Gmmap_page_size	PL_mmap_page_size
#define PL_Gmy_ctx_mutex	PL_my_ctx_mutex
#define PL_Gmy_cxt_index	PL_my_cxt_index
#define PL_Gop_mutex		PL_op_mutex
#define PL_Gop_seq		PL_op_seq
#define PL_Gop_sequence		PL_op_sequence
#define PL_Gpatleave		PL_patleave
#define PL_Gperlio_debug_fd	PL_perlio_debug_fd
#define PL_Gperlio_fd_refcnt	PL_perlio_fd_refcnt
#define PL_Gppaddr		PL_ppaddr
#define PL_Gsh_path		PL_sh_path
#define PL_Gsig_defaulting	PL_sig_defaulting
#define PL_Gsig_handlers_initted	PL_sig_handlers_initted
#define PL_Gsig_ignoring	PL_sig_ignoring
#define PL_Gsig_sv		PL_sig_sv
#define PL_Gsig_trapped		PL_sig_trapped
#define PL_Gsigfpe_saved	PL_sigfpe_saved
#define PL_Gsv_placeholder	PL_sv_placeholder
#define PL_Gthr_key		PL_thr_key
#define PL_Gtimesbase		PL_timesbase
#define PL_Guse_safe_putenv	PL_use_safe_putenv
#define PL_Gwatch_pvx		PL_watch_pvx

#endif /* PERL_GLOBAL_STRUCT */

#ifdef PERL_POLLUTE		/* disabled by default in 5.6.0 */

#define DBassertion		PL_DBassertion
#define DBsingle		PL_DBsingle
#define DBsub			PL_DBsub
#define compiling		PL_compiling
#define curcop			PL_curcop
#define curstash		PL_curstash
#define debstash		PL_debstash
#define defgv			PL_defgv
#define diehook			PL_diehook
#define dirty			PL_dirty
#define dowarn			PL_dowarn
#define errgv			PL_errgv
#define na			PL_na
#define no_modify		PL_no_modify
#define perl_destruct_level	PL_perl_destruct_level
#define perldb			PL_perldb
#define ppaddr			PL_ppaddr
#define rsfp			PL_rsfp
#define rsfp_filters		PL_rsfp_filters
#define stack_base		PL_stack_base
#define stack_sp		PL_stack_sp
#define stdingv			PL_stdingv
#define sv_arenaroot		PL_sv_arenaroot
#define sv_no			PL_sv_no
#define sv_undef		PL_sv_undef
#define sv_yes			PL_sv_yes
#define tainted			PL_tainted
#define tainting		PL_tainting

#endif /* PERL_POLLUTE */

/* ex: set ro: */
