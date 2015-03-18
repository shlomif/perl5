#!./perl

BEGIN {
    chdir 't' if -d 't';
    @INC = '../lib';
    require './test.pl';
}

use strict;
use warnings;

eval "require 'meta_notation.pm'";
if ($@) {
    fail("Could not find 'meta_notation.pm'");
}
else {

    is(_meta_notation("\007\010\011\c?Z\x{103}"), "^G^H^I^?Z\x{103}");

    if ($::IS_ASCII || $::IS_ASCII) {
        is(_meta_notation("\x{c1}\x{e2}"), 'M-AM-b');
        is(_meta_notation("\x{df}"), 'M-_');
    }
    else {  # EBCDIC platform
        # In the first iteration we are looking for a non-ASCII control; in
        # the second, a regular non-ASCII character.  SPACE marks the end of
        # most controls.  We test each to see that they are properly converted
        # to \x{...}
        foreach my $start (0x20, ord " ") {
            for (my $i = $start; $i < 256; $i++) {
                my $char = chr $i;
                next if $char =~ /[[:ascii:]]/;
                unless (is(_meta_notation($char), sprintf("\\x{%X}", $i))) {
                    my $m = _meta_notation($char);
                    my $s = sprintf("\\x{%X}", $i);
                    use bytes;
                    print STDERR __FILE__, ": ", __LINE__, ": meta_notation=", join(" ", map { sprintf "%02X", ord $_ } split("", $m)), "\n";
                    print STDERR __FILE__, ": ", __LINE__, ":       sprintf=", join(" ", map { sprintf "%02X", ord $_ } split("", $s)), "\n";
                }
                last;
            }
        }
    }
}

done_testing();
