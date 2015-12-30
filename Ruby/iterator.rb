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

printf [1,3,5,7,9].find { |v| v*v>30}.to_s

class JukeboxButton < Button
  def initialize(label, &action)
    super(label)
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
