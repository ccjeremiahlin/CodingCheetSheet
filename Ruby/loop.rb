#!/usr/bin/ruby

x=10
while x>=0 do
  puts x
  x-=1
end

x = 0
until x>10 do
  puts x
  x+=1
end

puts x-=1 while x > 0   # loop condition is tested first
puts x+=1 until x >= 10 # loop condition is tested first

x = 10
begin           # the begin-end body is executed first
  puts x        # before the condition is tested.
  x -= 1
end until x==0

array = [1, 2, 3, 4, 5]
for element in array
  print element, " "
end
puts

hash = {:a=>1, :b=>2, :c=>3}
for k,v in hash
  puts "#{k} => #{v}"
end

0.step(Math::PI, 0.1) {|x| puts Math.sin(x) }
