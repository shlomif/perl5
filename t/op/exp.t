#!./perl

BEGIN {
    chdir 't' if -d 't';
    @INC = '../lib';
    require './test.pl';
}

plan tests => 22;

# compile time evaluation

$s = sqrt(2);
is(substr($s,0,5), '1.414');

$s = exp(1);
is(substr($s,0,7), '2.71828');

cmp_ok(exp(log(1)), '==', 1);

# run time evaluation

$x1 = 1;
$x2 = 2;
$s = sqrt($x2);
is(substr($s,0,5), '1.414');

$s = exp($x1);
is(substr($s,0,7), '2.71828');

cmp_ok(exp(log($x1)), '==', 1);

# tests for transcendental functions

my $pi = 3.1415926535897931160;
my $pi_2 = 1.5707963267948965580;

sub round {
   my $result = shift;
   return sprintf("%.9f", $result);
}

# sin() tests
cmp_ok(sin(0), '==', 0.0);
cmp_ok(round(sin($pi)), '==', 0.0);
cmp_ok(round(sin(-1 * $pi)), '==', 0.0);
cmp_ok(round(sin($pi_2)), '==', 1.0);
cmp_ok(round(sin(-1 * $pi_2)), '==', -1.0);

# cos() tests
cmp_ok(cos(0), '==', 1.0);
cmp_ok(round(cos($pi)), '==', -1.0);
cmp_ok(round(cos(-1 * $pi)), '==', -1.0);
cmp_ok(round(cos($pi_2)), '==', 0.0);
cmp_ok(round(cos(-1 * $pi_2)), '==', 0.0);

# atan2() tests
cmp_ok(round(atan2(-0.0, 0.0)), '==', 0);
cmp_ok(round(atan2(0.0, 0.0)), '==', 0);
cmp_ok(round(atan2(-0.0, -0.0)), '==', round(-1 * $pi));
cmp_ok(round(atan2(0.0, -0.0)), '==', round($pi));
cmp_ok(round(atan2(-1.0, 0.0)), '==', round(-1 * $pi_2));
cmp_ok(round(atan2(1.0, 0.0)), '==', round($pi_2));
