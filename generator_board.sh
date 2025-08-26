#!/usr/bin/perl
use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;

open(my $fh, '>', "board.txt") or die "???: $!";

print "$y.ox\n";
print $fh "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "o";
            print $fh "o";
        }
        else {
            print ".";
            print $fh ".";
        }
    }
    print "\n";
    print $fh "\n";
}

close($fh);