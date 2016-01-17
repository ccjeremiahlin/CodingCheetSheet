#!/usr/bin/ruby
x = 5
name = case
        when x==1 then "one"
        when x==2 then "two"
        when x==3 then "three"
        else "many"
        end

puts name
puts
x, y = 2, 1
puts case
      when x==2 || y==1 then "x is two or y is one"
end

#
# case equality operator ===
#
puts case x
  when String then "string"
  when Numeric then "number"
  when TrueClass, FalseClass then "boolean"
  else "other"
end

income = 7600
tax = case income
      when 0..7550
        income * 0.1
      when 7550..30650
        755 + (income-7550) *0.15
      end
puts tax
