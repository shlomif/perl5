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
use vars qw(%insn_data @insn_name @optype @specialsv_name);

@optype = qw(OP UNOP BINOP LOGOP LISTOP PMOP SVOP PADOP PVOP LOOP COP);
@specialsv_name = qw(Nullsv &PL_sv_undef &PL_sv_yes &PL_sv_no);

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
$insn_data{xcv_depth} = [48, \&PUT_I32, "GET_I32"];
$insn_data{xcv_padlist} = [49, \&PUT_svindex, "GET_svindex"];
$insn_data{xcv_outside} = [50, \&PUT_svindex, "GET_svindex"];
$insn_data{xcv_flags} = [51, \&PUT_U8, "GET_U8"];
$insn_data{av_extend} = [52, \&PUT_I32, "GET_I32"];
$insn_data{av_push} = [53, \&PUT_svindex, "GET_svindex"];
$insn_data{xav_fill} = [54, \&PUT_I32, "GET_I32"];
$insn_data{xav_max} = [55, \&PUT_I32, "GET_I32"];
$insn_data{xav_flags} = [56, \&PUT_U8, "GET_U8"];
$insn_data{xhv_riter} = [57, \&PUT_I32, "GET_I32"];
$insn_data{xhv_name} = [58, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{hv_store} = [59, \&PUT_svindex, "GET_svindex"];
$insn_data{sv_magic} = [60, \&PUT_U8, "GET_U8"];
$insn_data{mg_obj} = [61, \&PUT_svindex, "GET_svindex"];
$insn_data{mg_private} = [62, \&PUT_U16, "GET_U16"];
$insn_data{mg_flags} = [63, \&PUT_U8, "GET_U8"];
$insn_data{mg_pv} = [64, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{xmg_stash} = [65, \&PUT_svindex, "GET_svindex"];
$insn_data{gv_fetchpv} = [66, \&PUT_strconst, "GET_strconst"];
$insn_data{gv_stashpv} = [67, \&PUT_strconst, "GET_strconst"];
$insn_data{gp_sv} = [68, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_refcnt} = [69, \&PUT_U32, "GET_U32"];
$insn_data{gp_refcnt_add} = [70, \&PUT_I32, "GET_I32"];
$insn_data{gp_av} = [71, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_hv} = [72, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_cv} = [73, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_file} = [74, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{gp_io} = [75, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_form} = [76, \&PUT_svindex, "GET_svindex"];
$insn_data{gp_cvgen} = [77, \&PUT_U32, "GET_U32"];
$insn_data{gp_line} = [78, \&PUT_U16, "GET_U16"];
$insn_data{gp_share} = [79, \&PUT_svindex, "GET_svindex"];
$insn_data{xgv_flags} = [80, \&PUT_U8, "GET_U8"];
$insn_data{op_next} = [81, \&PUT_opindex, "GET_opindex"];
$insn_data{op_sibling} = [82, \&PUT_opindex, "GET_opindex"];
$insn_data{op_ppaddr} = [83, \&PUT_strconst, "GET_strconst"];
$insn_data{op_targ} = [84, \&PUT_U32, "GET_U32"];
$insn_data{op_type} = [85, \&PUT_U16, "GET_U16"];
$insn_data{op_seq} = [86, \&PUT_U16, "GET_U16"];
$insn_data{op_flags} = [87, \&PUT_U8, "GET_U8"];
$insn_data{op_private} = [88, \&PUT_U8, "GET_U8"];
$insn_data{op_first} = [89, \&PUT_opindex, "GET_opindex"];
$insn_data{op_last} = [90, \&PUT_opindex, "GET_opindex"];
$insn_data{op_other} = [91, \&PUT_opindex, "GET_opindex"];
$insn_data{op_children} = [92, \&PUT_U32, "GET_U32"];
$insn_data{op_pmreplroot} = [93, \&PUT_opindex, "GET_opindex"];
$insn_data{op_pmreplrootgv} = [94, \&PUT_svindex, "GET_svindex"];
$insn_data{op_pmreplstart} = [95, \&PUT_opindex, "GET_opindex"];
$insn_data{op_pmnext} = [96, \&PUT_opindex, "GET_opindex"];
$insn_data{pregcomp} = [97, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{op_pmflags} = [98, \&PUT_U16, "GET_U16"];
$insn_data{op_pmpermflags} = [99, \&PUT_U16, "GET_U16"];
$insn_data{op_sv} = [100, \&PUT_svindex, "GET_svindex"];
$insn_data{op_padix} = [101, \&PUT_U32, "GET_U32"];
$insn_data{op_pv} = [102, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{op_pv_tr} = [103, \&PUT_op_tr_array, "GET_op_tr_array"];
$insn_data{op_redoop} = [104, \&PUT_opindex, "GET_opindex"];
$insn_data{op_nextop} = [105, \&PUT_opindex, "GET_opindex"];
$insn_data{op_lastop} = [106, \&PUT_opindex, "GET_opindex"];
$insn_data{cop_label} = [107, \&PUT_pvcontents, "GET_pvcontents"];
$insn_data{cop_stash} = [108, \&PUT_svindex, "GET_svindex"];
$insn_data{cop_filegv} = [109, \&PUT_svindex, "GET_svindex"];
$insn_data{cop_seq} = [110, \&PUT_U32, "GET_U32"];
$insn_data{cop_arybase} = [111, \&PUT_I32, "GET_I32"];
$insn_data{cop_line} = [112, \&PUT_U16, "GET_U16"];
$insn_data{cop_warnings} = [113, \&PUT_svindex, "GET_svindex"];
$insn_data{main_start} = [114, \&PUT_opindex, "GET_opindex"];
$insn_data{main_root} = [115, \&PUT_opindex, "GET_opindex"];
$insn_data{curpad} = [116, \&PUT_svindex, "GET_svindex"];

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
