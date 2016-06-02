//basically the same as in C/C++/Java

// for loop
var str_accum = "";
for(var i=0; i< 10; i++) {
  str_accum += i;
}
console.log(str_accum);

// loop through obj
var ary = [1, 2, 3];
ary.sth = 'sth';

console.log('loop through obj: in');
for (let i in ary) console.log(i); //including properties
console.log('loop through obj: of');
for (let i of ary) console.log(i); //only iterable items

//if else is trivial

//while is trivial

//do while is trivial

//switch case is trivial

