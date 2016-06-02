//re str.replace and parenthesized substring matches
var re = /(\w+)\s(\w+)/;
var str = "John Smith";
var newstr = str.replace(re, "$2, $1");
console.log(newstr);

//advanced searching with flags: g, i, m, y
var re = new RegExp("\\w+\\s", "g");
var str = "fee fi fo fum";
var myArray = str.match(re);
console.log(myArray);
