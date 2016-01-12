#!/usr/bin/ruby
:symbol
%s[symbol]
o = [1,2,3]
puts "here " + (o.respond_to? :each).to_s

name = :size
if o.respond_to?name
  puts o.send(name) # Note that we use send method to invoke the method
end

str = "string"
sym = str.intern
sym = str.to_sym #the same as intern
str = sym.to_s #convert back to a string
str = sym.id2name #another way to do that
