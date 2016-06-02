//multiple instances of the variable can be aliave at the same time.

function wrapValue(n) {
  var localVar = n;
  return function() {return localVar;};
};

var wrap1=wrapValue(1);
var wrap2=wrapValue(2);

console.log(wrap1());//1
console.log(wrap2());//2

//closure could be thought of that the function keyword as "freezing" the code
//in its body and wraping it into a package.


function multiplier(factor) {
  return function(number) {
    return number*factor;
  };
}

var twice = multiplier(2);
console.log(twice(5)); //10
console.log(twice(6)); //12

//call the outer function and specify arguments for both outer and inner function
function outside(x) {
  function inside(y) {
    return x+y;
  }
  return inside;
}
console.log(outside(3)(5));//8
