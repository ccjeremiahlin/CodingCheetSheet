#
# altering control flow
# return, break, next, redo, retry, throw, catch
#

# return (in a block)
# return always causes the *enclosing method* to return, regardless of how deeply nested within blocks it is.

def find(array, target)
  array.each_with_index do |element, index|
    return index if (element == target)
  end
  nil
end
puts find([1,2,3,4], 3)


# 
# break
# when used in a block, break transfers control out of the block, out of the iterator that invoked the block.
#
[1,2,3,4].each do |a|
  break if a==3
  print a, " "
end
puts "here"

#
# next
# using in block or loop,same meaning as continue in c/java
# special usage in block with return value
#

squareroots = [1, 2, -1, 3].collect do |x|
  next 0 if x<0
  Math.sqrt(x)
end
puts squareroots.to_s


#
# redo
# transfer control back to the top of the loop or block so that the iteration can start over.
# use case example: to recover from input errors when prompting a user for input.
puts "Please enter the first word you think of"
words = %w(apple banana cherry) # shorthand for ["apple", "banana", "cherry"]
response = words.collect do |word|
  # Control returns here when redo is executed
   print word + "> " # Prompt the user
   response = gets.chop # Get a response
   if response.size == 0 # If user entered nothing
    word.upcase! # Emphasize the prompt with uppercase
    redo # And skip to the top of the block
   end
   response # Return the response
end

#
# retry
# deprecated.
#


#
