BEGIN {
    chdir 't' if -d 't';
    @INC = qw(../lib uni .);
    require "case.pl";
}

casetest("Upper", \%utf8::ToSpecUpper, sub { uc $_[0] });

