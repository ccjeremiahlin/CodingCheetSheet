#!/usr/sbin/ruby

# A variable is simply a reference to an object. 
# Assignment of variable just copies the reference, not the object. 
# To copy the object, use dup

person1 = "Tim"
person2 = person1
person1[0] = 'J'
puts person1
puts person2

person3 = person1.dup
person3[0] = 'D'
puts person3
puts person1

person3.freeze # not allow others to modify
