class BankAccount
  def init(name, checking, savings)
    @name, @checking, @savings = name, checking, savings
    @lock = Mutex.new
  end

  def transfer_from_savings(x)
    @lock.synchronize {
      @savings -= x
      @checking += x
    }
  end

  def report
    @lock.synchronize {
      "#@name\nChecking: #@checking\nSavings: #@savings"
    }
  end
end
