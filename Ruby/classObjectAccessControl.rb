#!/usr/sbin/ruby
#
# Public Methods: can be called by anyone
#
# Protected Methods: can be invoked only by objects of the defining class and its subclasses. Access is kept within the family. 
#
# Private Methods: cannot be called with an explicit receiver; can only be called in the defining class and by direct descendents wiithin that same object.
#
#

class MyClass
  def method1
  end
  def method2
  end
  def method3
  end

  public :method1
  private :method2
  protected :method3
end

# initiailze is automatically declared to be private.
