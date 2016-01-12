#!/usr/bin/ruby
a1 = %w( last first second)
a1.each { |s| puts s }
a2 = %w| 1 2 3|
a2.each { |s| print s }
puts
puts "pi is about %.4f" % Math::PI
puts "%s: %f" % ["pi", Math::PI]

#
# %q begins a string literal that follows single-quoted string rules.
# %Q follows double-quoted string rules.
# The first character following q or Q is the delimiter character, and
# the string literal continues until a matching (unescaped) delimiter
# is found.
# If the opening delimiter is (, [, {, or <, then the matching
# delimiter is ), }, or >.
#
puts %q(Don't worry about escaping ' characters!)
puts %Q|"How are you?", he said|
puts %Q-This string literal ends with a newline \n-

#
# Here Document << <<-
# Omitted.


#
# Backtick command execution
# return the output of the command as a "string"
#
a = `ls`

#
# String.new 
#

b = String.new
puts b


#
# String operations
#  
#  +  creates a new string for the lefthand and righthand operands;
#  <<  alters the lefthand operand rather then creating and returning
#  a new object

planet = "Earth"
puts "Hello" + " " + planet
planet_number = 1005
puts "Hello planet #" + planet_number.to_s
puts "Hello planet ##{planet_number}"

greeting = "Hello"
greeting << " " << "World"
puts greeting

#
# indexing string with string 
#

s = "hello"
while(s["l"])
  s["l"] = "L"
end
puts s

#
# indexing a string using a regular expression
#
s = "google"
vowel = /[aeiou]/
while(s[vowel])
  s[vowel] = '*'
end

puts s
