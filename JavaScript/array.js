//array methods
//concat, join, push, pop, shift, unshift, slice(start_index, upto_index)
//splice(index, count_to_move, addElement1, addElement2, ...)
//reverse, sort, sort(fn), indexOf, lastIndexOf, filter, every, some, reduce, reduceRight

//working with array-like objects
function printArguments() {
  Array.prototype.forEach.call(arguments, function(item){
    console.log(item);
  });
}
printArguments(1, 2, 3, 4, 5);
