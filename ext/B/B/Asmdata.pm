#
#      Copyright (c) 1996-1999 Malcolm Beattie
#
#      You may distribute under the terms of either the GNU General Public
#      License or the Artistic License, as specified in the README file.
#
#
#
# This file is autogenerated from bytecode.pl. Changes made here will be lost.
#
package B::Asmdata;
use Exporter;
@ISA = qw(Exporter);
@EXPORT_OK = qw(%insn_data @insn_name @optype @specialsv_name);
our(%insn_data, @insn_name, @optype, @specialsv_name);

@optype = qw(OP UNOP BINOP LOGOP LISTOP PMOP SVOP PADOP PVOP LOOP COP);
@specialsv_name = qw(Nullsv &PL_sv_undef &PL_sv_yes &PL_sv_no pWARN_ALL pWARN_NONE);

# XXX insn_data is initialised this way because with a large
# %insn_data = (foo => [...], bar => [...], ...) initialiser
# I get a hard-to-track-down stack underflow and segfault.
$insn_data{comment} = [35, \&PUT_comment_t, "GET_comment_t"];
$insn_data{nop} = [10, \&PUT_none, "GET_none"];
$insn_data{ret} = [0, \&PUT_none, "GET_none"];
$insn_data{ldsv} = [1, \&PUT_svindex, "GET_svindex"];
$insn_data{ldop} = [2, \&PUT_opindex, "GET_opindex"];
$insn_data{stsv} = [3, \&PUT_U32, "GET_U32"];
$insn_data{stop} = [4, \&PUT_U32, "GET_U32"];
$insn_data{ldspecsv} = [5, \&PUT_U8, "GET_U8"];
$insn_data{newsv} = [6, \&PUT_U8, "GET_U8"];
$insn_data{newop} = [7, \&PUT_U8, "GET_U8"];
$insn_data{newopn} = [8, \&PUT_U8, "GET_U8"];
$insn_data{newpv} = [9, \&PUT_PV, "GET_PV"];
$insn_data{pv_cur} = [11, \&PUT_U32, "GET_U32"];
$insn_data{pv_free} = [12, \&PUT_none, "GET_none"];
$insn_data{sv_upgrade} = [13, \&PUT_U8, "GET_U8"];
$insn_data{sv_refcnt} = [14, \&PUT_U32, "GET_U32"];
$insn_data{sv_refcnt_add} = [15, \&PUT_I32, "GET_I32"];
$insn_data{sv_flags} = [16, \&PUT_U32, "GET_U32"];
$insn_data{xrv} = [17, \&PUT_svindex, "GET_svindex"];
$insn_data{xpv} = [18, \&PUT_none, "GET_none"];
$insn_data{xiv32} = [19, \&PUT_I32, "GET_I32"];
$insn_data{xiv64} = [20, \&PUT_IV64, "GET_IV64"];
$insn_data{xnv} = [21, \&PUT_NV, "GET_NV"];
$insn_data{xlv_targoff} = [22, \&PUT_U32, "GET_U32"];
$insn_data{xlv_targlen} = [23, \&PUT_U32, "GET_U32"];
$insn_data{xlv_targ} = [24, \&PUT_svindex, "GET_svindex"];
$insn_data{xlv_type} = [25, \&PUT_U8, "GET_U8"];
$insn_data{xbm_useful} = [26, \&PUT_I32, "GET_I32"];
$insn_data{xbm_previous} = [27, \&PUT_U16, "GET_U16"];
$insn_data{xbm_rare} = [28, \&PUT_U8, "GET_U8"];
$insn_data{xfm_lines} = [29, \&PUT_I32, "GET_I32"];
$insn_data{xio_lines} = [30, \&PUT_I32, "GET_I32"];
$insn_data{xio_page} = [31, \&PUT_I32, "GET_I32"];
$insn_data{xio_page_len} = [32, \&PUT_I32, "GET_I32"];
$insn_data{xio_lines_left} = [33, \&PUT_I32, "GET_I32"];
$insn_data{xio_top_name} = [34, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{xio_top_gv} = [36, \&PUT_svindex, "GET_svindex"];
$insn_data{xio_fmt_name} = [37, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{xio_fmt_gv} = [38, \&PUT_svindex, "GET_svindex"];
$insn_data{xio_bottom_name} = [39, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{xio_bottom_gv} = [40, \&PUT_svindex, "GET_svindex"];
$insn_data{xio_subprocess} = [41, \&PUT_U16, "GET_U16"];
$insn_data{xio_type} = [42, \&PUT_U8, "GET_U8"];
$insn_data{xio_flags} = [43, \&PUT_U8, "GET_U8"];
$insn_data{xcv_stash} = [44, \&PUT_svindex, "GET_svindex"];
$insn_data{xcv_start} = [45, \&PUT_opindex, "GET_opindex"];
$insn_data{xcv_root} = [46, \&PUT_opindex, "GET_opindex"];
$insn_data{xcv_gv} = [47, \&PUT_svindex, "GET_svindex"];
$insn_data{xcv_file} = [48, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{xcv_depth} = [49, \&PUT_I32, "GET_I32"];
$insn_data{xcv_padlist} = [50, \&PUT_svindex, "GET_svindex"];
$insn_data{xcv_outside} = [51, \&PUT_svindex, "GET_svindex"];
$insn_data{xcv_flags} = [52, \&PUT_U16, "GET_U16"];
$insn_data{av_extend} = [53, \&PUT_I32, "GET_I32"];
$insn_data{av_push} = [54, \&PUT_svindex, "GET_svindex"];
$insn_data{xav_fill} = [55, \&PUT_I32, "GET_I32"];
$insn_data{xav_max} = [56, \&PUT_I32, "GET_I32"];
$insn_data{xav_flags} = [57, \&PUT_U8, "GET_U8"];
$insn_data{xhv_riter} = [58, \&PUT_I32, "GET_I32"];
$insn_data{xhv_name} = [59, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{hv_store} = [60, \&PUT_svindex, "GET_svindex"];
$insn_data{sv_magic} = [61, \&PUT_U8, "GET_U8"];
$insn_data{mg_obj} = [62, \&PUT_svindex, "GET_svindex"];
$insn_data{mg_private} = [63, \&PUT_U16, "GET_U16"];
$insn_data{mg_flags} = [64, \&PUT_U8, "GET_U8"];
$insn_data{mg_pv} = [65, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{xmg_stash} = [66, \&PUT_svindex, "GET_svindex"];
$insn_data{gv_fetchpv} = [67, \&PUT_strconst, "GET_strconst"];
$insn_data{gv_stashpv} = [68, \&PUT_strconst, "GET_strconst"];
$insn_data{gp_sv} = [69, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_refcnt} = [70, \&PUT_U32, "GET_U32"];
$insn_data{gp_refcnt_add} = [71, \&PUT_I32, "GET_I32"];
$insn_data{gp_av} = [72, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_hv} = [73, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_cv} = [74, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_file} = [75, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{gp_io} = [76, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_form} = [77, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_cvgen} = [78, \&PUT_U32, "GET_U32"];
$insn_data{gp_line} = [79, \&PUT_U16, "GET_U16"];
$insn_data{gp_share} = [80, \&PUT_svindex, "GET_svindex"];
$insn_data{xgv_flags} = [81, \&PUT_U8, "GET_U8"];
$insn_data{op_next} = [82, \&PUT_opindex, "GET_opindex"];
$insn_data{op_sibling} = [83, \&PUT_opindex, "GET_opindex"];
$insn_data{op_ppaddr} = [84, \&PUT_strconst, "GET_strconst"];
$insn_data{op_targ} = [85, \&PUT_U32, "GET_U32"];
$insn_data{op_type} = [86, \&PUT_U16, "GET_U16"];
$insn_data{op_seq} = [87, \&PUT_U16, "GET_U16"];
$insn_data{op_flags} = [88, \&PUT_U8, "GET_U8"];
$insn_data{op_private} = [89, \&PUT_U8, "GET_U8"];
$insn_data{op_first} = [90, \&PUT_opindex, "GET_opindex"];
$insn_data{op_last} = [91, \&PUT_opindex, "GET_opindex"];
$insn_data{op_other} = [92, \&PUT_opindex, "GET_opindex"];
$insn_data{op_children} = [93, \&PUT_U32, "GET_U32"];
$insn_data{op_pmreplroot} = [94, \&PUT_opindex, "GET_opindex"];
$insn_data{op_pmreplrootgv} = [95, \&PUT_svindex, "GET_svindex"];
$insn_data{op_pmreplstart} = [96, \&PUT_opindex, "GET_opindex"];
$insn_data{op_pmnext} = [97, \&PUT_opindex, "GET_opindex"];
$insn_data{pregcomp} = [98, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{op_pmflags} = [99, \&PUT_U16, "GET_U16"];
$insn_data{op_pmpermflags} = [100, \&PUT_U16, "GET_U16"];
$insn_data{op_sv} = [101, \&PUT_svindex, "GET_svindex"];
$insn_data{op_padix} = [102, \&PUT_U32, "GET_U32"];
$insn_data{op_pv} = [103, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{op_pv_tr} = [104, \&PUT_op_tr_array, "GET_op_tr_array"];
$insn_data{op_redoop} = [105, \&PUT_opindex, "GET_opindex"];
$insn_data{op_nextop} = [106, \&PUT_opindex, "GET_opindex"];
$insn_data{op_lastop} = [107, \&PUT_opindex, "GET_opindex"];
$insn_data{cop_label} = [108, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{cop_stashpv} = [109, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{cop_file} = [110, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{cop_seq} = [111, \&PUT_U32, "GET_U32"];
$insn_data{cop_arybase} = [112, \&PUT_I32, "GET_I32"];
$insn_data{cop_line} = [113, \&PUT_U16, "GET_U16"];
$insn_data{cop_warnings} = [114, \&PUT_svindex, "GET_svindex"];
$insn_data{main_start} = [115, \&PUT_opindex, "GET_opindex"];
$insn_data{main_root} = [116, \&PUT_opindex, "GET_opindex"];
$insn_data{curpad} = [117, \&PUT_svindex, "GET_svindex"];
$insn_data{push_begin} = [118, \&PUT_svindex, "GET_svindex"];
$insn_data{push_init} = [119, \&PUT_svindex, "GET_svindex"];
$insn_data{push_end} = [120, \&PUT_svindex, "GET_svindex"];

my ($insn_name, $insn_data);
while (($insn_name, $insn_data) = each %insn_data) {
    $insn_name[$insn_data->[0]] = $insn_name;
}
# Fill in any gaps
@insn_name = map($_ || "unused", @insn_name);

1;

__END__

=head1 NAME

B::Asmdata - Autogenerated data about Perl ops, used to generate bytecode

=head1 SYNOPSIS

	use Asmdata;

=head1 DESCRIPTION

See F<ext/B/B/Asmdata.pm>.

=head1 AUTHOR

Malcolm Beattie, C<mbeattie@sable.ox.ac.uk>

=cut
