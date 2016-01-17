#!/usr/bin/ruby
def fibUpTo(max)
  i1, i2 = 1, 1
  while i1 <= max
    yield i1
    i1, i2 = i2, i1+i2
  end
end
fibUpTo(1000) {|f| print f, ' '}

puts

class Array
  def find
    for i in 0...size
      value = self[i]
      return value if yield(value)
    end
    return nil
  end
end

printf [1,3,5,7,9].find { |v| v*v>30 }.to_s

class JukeboxButton
  def initialize(label, &action)
    @action = action
  end
  def buttonPressed
    @action.call(self)
  end
end

bStart = JukeboxButton.new("Start") { songList.start }
bPause = JukeboxButton.new("Pause") { songList.pause }

def nTimes(aThing)
  return proc { |n| aThing * n }
end
p1 = nTimes(23)
p1.call(3)
p1.call(4)
p2 = nTimes("Hello ")
p2.call(3)
puts
#
# numeric iterator
#
1.upto(3) { |x| print x, " "}

#
# File
#
File.open(__FILE__) do |f|
  f.each_with_index do |line,number|
    print "#{number}: #{line}"
  end
end
puts
#
# collect, select, odds
#

squares = [1,2,3].collect {|x| x*x}
puts squares.to_s

evens = (1..10).select {|x| x%2 ==0}
puts evens.to_s

odds = (1..10).reject {|x| x%2 == 0}
puts odds.to_s

data = [2,5,3,4]
sum = data.inject { |sum, x| sum+=x}
puts sum.to_s
floatprod = data.inject(1.0) {|p,x| p*x}
puts floatprod.to_s

#
# Enumerable
#
s = "hello"
sc =  s.enum_for(:each_char).map { |c| c.succ}
puts sc.to_s

#
# External Iterator
#
iterator = 9.downto(1)
begin
  print iterator.next while true
rescue StopIteration
  puts "...blastoff!"
end

#
# Loop : an implicit rescue clause and exits cleanly when StopIteration is raised.
#        for external iterator.
iterator = 9.downto(1)
loop do 
  print iterator.next
end
puts "...blastoff!"

#
# Parallel iteration and external iterations
# tl;dr 
