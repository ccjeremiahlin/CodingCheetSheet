#!/usr/bin/ruby

class Song
  @@plays=0
  # 
  # 1. Initialization
  # 1.1 Default Argument
  #
  attr_reader :duration, :name
  def initialize(name, artist, duration=60)
    @name       = name
    @artist     = artist
    @duration   = duration
    @plays=0
  end
  #
  # Override
  #
  def to_s
    @name + " " + @artist + " " + "#{@duration}"
  end
  #
  # Class Variables
  #
  def play
    @plays+=1
    @@plays+=1
    "This song: #@plays plays. Total #@@plays plays."
  end
end

#
# 2. Calling function with multiple arguments, use parenthese
#

hello = Song.new("Hello", "Adele", 4)
puts hello.to_s

#
# 3. Inheritance
#

class KaraokeSong < Song
  def initialize(name, artist, duration, lyrics)
    super(name, artist, duration)
    @lyrics = lyrics
  end 
  def to_s
    super + " #{@lyrics}"
  end
end

ks = KaraokeSong.new("Hello", "Adele", 4, "Hello, how are you?\n")
puts ks.to_s

#
# 4. Object and Attributes
#

class Single < Song
  # => reader attribute
  # attr_reader :name, :artist, :year
  # attr_writer :name, :artist, :year
  attr_accessor :name, :artist, :year, :duration
  def initialize(name, artist, year)
    super(name, artist)
    @year = year
  end
  #
  # Virtual Attributes
  #
  def durationInMinutes
    @duration/60.0
  end
  def durationInMinutes=(value)
    @duration = (value*60).to_i
  end
end

asingle = Single.new("Hello", "Adele", 2015)
asingle.durationInMinutes = 1
puts "Duration of " + asingle.to_s + " is #{asingle.duration} seconds = #{asingle.durationInMinutes} minutes"

puts hello.play
puts ks.play
puts asingle.play

#
# 5. Class Method
#
class SongList
  MaxTime = 5*60  # 5 minutes
  def SongList.isTooLong(aSong)
    return "Is song #{aSong.name} too long? " + (aSong.duration > MaxTime).to_s
  end
end

song1 = Song.new("Bycilops", "Fleck", 260)
puts SongList.isTooLong(song1)
song2 = Song.new("The Calling", "Santana", 468)
puts SongList.isTooLong(song2)

#
# 6. Object Methods
#

o = "some string"
puts o.class.to_s
puts o.instance_of? String
puts o.is_a? Object
puts Object === o

#
# 7. Equality
#     .equal?  is used to test whether two values refer to exactly the same object.

a = "Ruby"
b = c = "Ruby"
puts a.equal?(b)
puts b.equal?(c)

# 
# 7.1 == operator
#
# Most classes redefine "==" operator for testing the value equality.

# 
# 8. Object Order
#
# classes define an ordering by implementing the <=> operator.
# which returns -1, 0, 1
# 
# Comparable mixin module defining: <, <=, ==, >=, >, and between?()

#
# 9. Conversion
#
# 9.1 String, Array, Hash, Regexp, and IO all defines a class method named try_convert
#
# ex: Array.try_convert(o) returns o.to_ary if o defines that method; otherwise it returns nil.
#
# 9.2 coerse
#

#
# 10. Copying object
# clone and dup return a shallow copy of the object on which they are invoked.
# unless the object being copied defines an initialize_copy() method.
# classes can redefine clone and dup to produce any kind of copy desired.
#
# 10.1 Marshal

def deepcopy(o)
  Marshal.load(Marshal.dump(0))
end

#
# 11. Frozen objects
#

s = "ice"
s.freeze
puts s.frozen?

#
# 12. Tainting Object
# Marking unsafe objects
#
s = "untrusted"
s.taint
puts s.tainted?
s.upcase.tainted?
s[3,4].tainted?
