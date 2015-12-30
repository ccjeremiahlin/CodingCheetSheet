#!ruby
ARGF.each { |line| print line if line =~ /Ruby|\d\d:\d\d:\d\d|Space\sSpace/ }
