#!/bin/usr/ruby

#
# Passing arguments to a block
#

def two; yield 1,2;end
two {|x| p x}
two {|*x| p x}
two {|x, | p x}

def five; yield 1,2,3,4,5; end
five {|head, *body, tail| p head, body, tail}

def hashiter; yield :a=>1, :b=>2; end
hashiter {|hash| p hash[:a]}
