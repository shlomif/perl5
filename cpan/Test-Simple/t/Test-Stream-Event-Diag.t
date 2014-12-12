use strict;
use warnings;

use Test::Stream;
use Test::More;

use ok 'Test::Stream::Event::Diag';

# the intercept stops the diag message '# hello' polluting STDERR
my ($stream, $old) = Test::Stream->intercept_start();
my $ctx = context(-1); my $line = __LINE__;
Test::Stream->intercept_stop($stream);

$ctx = $ctx->snapshot;
is($ctx->line, $line, "usable context");

my $diag = $ctx->diag('hello');

ok($diag, "build diag");
isa_ok($diag, 'Test::Stream::Event::Diag');
is($diag->message, 'hello', "message");

is_deeply(
    [$diag->to_tap],
    [[Test::Stream::Event::Diag::OUT_ERR, "# hello\n"]],
    "Got tap"
);

done_testing;
