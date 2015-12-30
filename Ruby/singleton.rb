#!/usr/sbin/ruby

class Logger
  private_class_method :new
  @@logger = nil
  def Logger.create
    @@logger = new unless @@logger
    @@logger
  end
end

puts Logger.create.__id__
puts Logger.create.__id__
