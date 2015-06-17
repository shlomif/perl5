#!./perl

use strict;
use warnings;

# What does this test?
# This tests for lack of "\t" and for lack of trailing spaces in files that
# already don't have them, so they won't be added later.

use Config;
use File::Spec;

BEGIN {
    @INC = '..' if -f '../TestInit.pm';
}
use TestInit qw(T); # T is chdir to the top level

require 't/test.pl';

skip_all("Cross-compiling, the entire source might not be available")
    if $Config{usecrosscompile};

my $pod_dir = File::Spec->catdir(File::Spec->curdir, 'pod');
opendir my $dh, $pod_dir
    or die "Cannot open pod directory. - $!";
my @pod_files = File::Spec->no_upwards(readdir($dh));
closedir($dh);

my %whitelist =
(
    map { $_ => 1 }
    qw(
perl5004delta.pod
perl5005delta.pod
perl5100delta.pod
perl5101delta.pod
perl5120delta.pod
perl5121delta.pod
perl5125delta.pod
perl5140delta.pod
perl5141delta.pod
perl5160delta.pod
perl5180delta.pod
perl5200delta.pod
perl5201delta.pod
perl561delta.pod
perl56delta.pod
perl581delta.pod
perl582delta.pod
perl583delta.pod
perl585delta.pod
perl587delta.pod
perl588delta.pod
perl589delta.pod
perl58delta.pod
perlaix.pod
perlamiga.pod
perlandroid.pod
perlapi.pod
perlbook.pod
perlcall.pod
perlce.pod
perlclib.pod
perlcn.pod
perldata.pod
perldbmfilter.pod
perldebguts.pod
perldebtut.pod
perldebug.pod
perldiag.pod
perldos.pod
perlembed.pod
perlfilter.pod
perlform.pod
perlfunc.pod
perlgit.pod
perlguts.pod
perlhurd.pod
perlintern.pod
perlinterp.pod
perliol.pod
perlirix.pod
perljp.pod
perllinux.pod
perllocale.pod
perllol.pod
perlmacos.pod
perlmacosx.pod
perlmodinstall.pod
perlmodlib.pod
perlmod.pod
perlmodstyle.pod
perlmroapi.pod
perlnetware.pod
perlnewmod.pod
perlnumber.pod
perlop.pod
perlos2.pod
perlos400.pod
perlpacktut.pod
perlplan9.pod
perl.pod
perlpod.pod
perlpodspec.pod
perlpolicy.pod
perlport.pod
perlpragma.pod
perlqnx.pod
perlreapi.pod
perlrebackslash.pod
perlreftut.pod
perlre.pod
perlrequick.pod
perlretut.pod
perlrun.pod
perlsec.pod
perlsolaris.pod
perlstyle.pod
perlsub.pod
perlsymbian.pod
perltie.pod
perltoc.pod
perltrap.pod
perltru64.pod
perltw.pod
perlunifaq.pod
perluniprops.pod
perlunitut.pod
perlutil.pod
perlvar.pod
perlvms.pod
perlwin32.pod
    )
);

sub _slurp
{
    my $filename = shift;

    open my $in, '<', $filename
        or die "Cannot open '$filename' for slurping - $!";

    local $/;
    my $contents = <$in>;

    close($in);

    return $contents;
}

foreach my $fn (@pod_files)
{
    if (( !exists($whitelist{$fn}) ) and ($fn =~ /\.pod\z/))
    {
        my $contents = _slurp(File::Spec->catfile($pod_dir, $fn));

        unlike ($contents, qr/\t/, "pod/$fn does not contain hard tabs.");
        unlike ($contents, qr/[ \t]$/m,
            "pod/$fn does not contain lines with trailing whitespace"
        );
    }
}

done_testing();
