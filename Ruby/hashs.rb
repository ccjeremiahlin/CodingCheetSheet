#!/bin/ruby
myhash = {}
0.upto(4) {|i| myhash["#{i}"]=i}
0.upto(4) {|i| print myhash["#{i}"]}
puts "end"
