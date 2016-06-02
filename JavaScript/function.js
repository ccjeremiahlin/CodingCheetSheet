//function declarations are hoisted
function foo() {
  bar();//ok, bar is hoisted.
  function bar() {
  }
}

//var is hoisted too, but assignment performed by them are not.

function foo() {
  bar(); // not okay, bar is not defined.
  var bar = function () {
  };
}

//special variable 'arguments'
function f() { return arguments }
var args = f('a','b','c');
console.log(args.length);//3
console.log(args[0]);//'a'

//too few or too many arguments
function f2(x, y) {
  console.log(x, y);
  console.log(Array.prototype.slice.call(arguments));
}
f2('a','b','c');

//optional parameters
function pair(x,y) {
  x=x||0; y=y||0; //||= is not valid in javascript (sigh)
  return [x, y];
}
console.log(pair());//[0, 0]
console.log(pair(3));//[3, 0]
console.log(pair(3,5));//[3, 5]

//default parameter
function multiply(a, b=1) {
  return a*b;
}
console.log(multiply(5));

//reset parameter
function multiply2(multiplier, ...theArgs) {
  return theArgs.map(x => multiplier * x);
}
var arr = multiply2(2, 1, 2, 3);
console.log(arr);
