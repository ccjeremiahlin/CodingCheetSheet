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

(1..10)    === 5  
(1..10)    === 15 
(1..10)    === 3.14159 
('a'..'j') === 'c'  # true
('a'..'j') === 'z'  # false


