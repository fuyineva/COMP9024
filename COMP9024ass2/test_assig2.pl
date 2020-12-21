#!/usr/bin/perl -w

my $file_loc = "./poG";
my $test_loc = "tests.in";

if($#ARGV == 0) {
  $file_loc = $ARGV[0];
}

if($#ARGV == 1) {
  $file_loc = $ARGV[0];
  $test_loc = $ARGV[1];
}

open my $f, "<", $test_loc or die("Tests file could not be opened.");
if( ! -f $file_loc) {
  die("Program file could not be found.");
}

foreach my $test (<$f>) {
  chomp $test;
  my $test_out = "test_$test.out";
  if( ! -f $test_out) {
    open my $to, ">", $test_out or die("Output file could not be opened");
    my $output = `$file_loc $test`;
    print $to $output;
    close $to;
    print "$test_out not found, created file from program output\n";
  } else {
    my $diff = `$file_loc $test | diff -b $test_out -`;
    if(length $diff) {
      print "TEST $test FAILED\n";
      print $diff;
    } else {
      print "TEST $test PASSED\n";
    }
  }
}

close $f;