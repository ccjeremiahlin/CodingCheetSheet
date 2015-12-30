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
