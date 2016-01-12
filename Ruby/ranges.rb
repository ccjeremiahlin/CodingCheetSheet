#!/usr/bin/ruby

# .. inclusive range
# ... excludes the specified high value
#
printf (1..10).to_a.to_s
puts
printf (1...10).to_a.to_s

class VU

  include Comparable

  attr :volume

  def initialize(volume)  # 0..9
    @volume = volume
  end

  def inspect
    '#' * @volume
  end

  # Support for ranges

  def <=>(other)
    self.volume <=> other.volume
  end

  def succ
    raise(IndexError, "Volume too big") if @volume >= 9
    VU.new(@volume.succ)
  end
end
puts
puts (1..10)    === 5  
puts (1..10)    === 15 
puts (1..10)    === 3.14159 
puts ('a'..'j') === 'c'  # true
puts ('a'..'j') === 'z'  # false

r = 0...100
puts r.member? 50
puts r.include? 100
puts r.include? 99.9
puts r.cover? 99

triples = "AAA"..."ZZZ"
puts "include ABCD " + (triples.include? "ABCD").to_s
puts triples.member? "ABCD"
puts triples.cover? "ABCD"
