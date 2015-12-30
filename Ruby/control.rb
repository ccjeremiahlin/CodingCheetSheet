def control(count, tries)
  if count.to_i > 10
    puts "Try again #{count}"
  elsif tries == 3
    puts "You lose #{count}"
  else
    puts "End #{count}" 
  end
end

tries = 0
count = 0
while !count.eql?"q\n"
  control(count, tries)
  count = gets
  tries += 1
end
