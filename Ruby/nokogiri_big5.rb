require 'open-uri'
require 'nokogiri'
require 'iconv'

to, from = 'utf-8', 'big5'
ic = Iconv.new(to, from)
doc = Nokogiri::HTML(ic.iconv(open("some big5 encoging page")), nil, "Big5")
doc.search("td").map do |cell|
  puts cell.text
end
