#!/usr/bin/ruby
line = 'Python is awesome'
puts line

if line =~ /Python .*/
  puts 'match python'
end

line2 = line.sub(/Python/, "Ruby")
puts "----" + line + " " + line2 + "----"
line3 = line+" "+line2
line4 = line3.gsub(/Python|Ruby/, "C++")
puts "----" + line4 + "----"

a = Regexp.new('^\s*[a-z]') #/^\s*[a-z]/
b = /^\s*[a-z]/             #/^\s*[a-z]/
c = %r{^\s*[a-z]}           #/^\s*[a-z]/

def showRE(a,re)
  if a =~ re
    "#{$`}<<#{$&}>>#{$'}"
  else
    "no match"
  end
end
showRE('very interesting', /t/) # very in<<t>>eresting
showRE('Fats Waller', /ll/) # Fats Wa<<ll>>er

#
# Anchors: ^, $, \A, \Z, \b (boundary), \B (not boundary)
#

#
# Character Classes []
# []] # matching ] 
# [-] # matching -
# [^a-z] # negate a-z, matches any character that isn't a lowercase alphabtic.
#
# \d (digit), \D (non-digit), \s (white space), \S (nonwhitespace), \w (word character), \W (nonword character)
#

#
# Repetition
# *, +, ?, {m,n} {m,}

puts "12:50am" =~ /(\d\d):(\d\d)(..)/  # 0
puts "Hour is #$1, minute #$2" # "Hour is 12, minute 50"
puts "12:50am" =~ /((\d\d):(\d\d))(..)/  # 0
puts "Time is #$1" # "Time is 12:50"
puts "Hour is #$2, minute #$3" # "Hour is 12, minute 50"
puts "AM/PM is #$4"  # "AM/PM is am"
#The ability to use part of the current match later in that match allows you to look for various forms of repetition.
# match duplicated letter
showRE('He said "Hello"', /(\w)\1/) # He said "He<<ll>>o"
# match duplicated substrings
showRE('Mississippi', /(\w+)\1/)  # M<<ississ>>ippi
showRE('He said "Hello"', /(["']).*?\1/)  # He said <<"Hello">>
showRE("He said 'Hello'", /(["']).*?\1/)  # He said <<'Hello'>>

a = "the quick brown fox"
a.sub(/^./) { $&.upcase } # "The quick brown fox"
a.gsub(/[aeiou]/) { $&.upcase } # "thE qUIck brOwn fOx"

re = /(\d+):(\d+)/     # match a time hh:mm
md = re.match("Time: 12:34am")
md.type » MatchData
md[0]         # == $& » "12:34"
md[1]         # == $1 » "12"
md[2]         # == $2 » "34"
md.pre_match  # == $` » "Time: "
md.post_match # == $' » "am"
