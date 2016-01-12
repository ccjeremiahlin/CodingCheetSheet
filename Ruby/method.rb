#!/usr/bin/ruby

#
# 1. Variable-length argument lists
#
def varargs(arg1, *rest)
  puts "Got #{arg1} and #{rest.join(', ')}"
end
varargs("one")
varargs("one", "two")
varargs("one", "two", "three")

#
# 2. Methods and Blocks
#
def takeBlock(p1)
  if block_given?
    yield(p1)
  else
    puts p1
  end
end

takeBlock("No block")
takeBlock("No block") do  |s|
  puts s.sub(/No /, '')
end

#
# 3. Proc Object
#
#
class TaxCalculator
  def initialize(name, &block)
    @name, @block = name, block
  end
  def getTax(amount)
    "#@name on #{amount} = #{@block.call(amount)}"
  end
end

tc = TaxCalculator.new("Sales tax") { |amt| amt*0.075 }
puts tc.getTax(100)
puts tc.getTax(250)

#
# 4. implicit receiver: self
#

puts self.__id__
puts __id__

#
# 5. reverse variable-length, expanding arrays in method call
#
def five(a, b, c, d, e)
  puts "I was passed #{a} #{b} #{c} #{d} #{e}"
end

five(1, 2, 3, 4, 5)
five(1, 2, 3, *['a', 'b'])
five(*(10..14).to_a)

#
# 6. More Proc Object
#

print "(t)imes or (p)lus: "
times = gets
print "number :"
number = gets.to_i

if times =~ /^t/
  calc = proc { |n| n*number }
else
  calc = proc { |n| n+number }
end
puts ((1..10).collect(&calc).join(', '))
