def method_name(x)
# The body of the method goes here.
# Usually, the method body runs to completion without exceptions # and returns to its caller normally.
rescue
# Exception-handling code goes here.
# If an exception is raised within the body of the method, or if # one of the methods it calls raises an exception, then control # jumps to this block.
puts $!, $@
# $! the last exception object raised. 
# $@ the stack trace of the last exception, equivalent to $!.backtrace
else
# If no exceptions occur in the body of the method # then the code in this clause is executed.
ensure
# The code in this clause is executed no matter what happens in the
# body of the method. It is run if the method runs to completion, if
# it throws an exception, or if it executes a return statement.
end
