#!/usr/sbin/ruby

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
