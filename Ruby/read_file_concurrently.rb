require 'English'
def conread(filenames)
  h = {}
  filenames.each do |filename|
    h[filename] = Thread.new do
      open(filename) {|f| f.read}
    end
  end

  h.each_pair do |filename, thread|
    begin
      h[filename] = thread.value
    rescue => ex
      puts "#{ex.class}: #{ex.message}"
      h[filename] = $!
    end
  end
end
