var str = 'abc';
console.log('str == "abc" and str[1] is ' + str[1]); //'b'
console.log('str == "abc" and "abc".length == ' + str.length); //3

console.log('str == "abc" and str.slice(1) == ' + str.slice(1)); //'bc'
console.log('str == "abc" and str.slice(1,2)) == ' + str.slice(1,2)); //'b'

console.log('str == "abc" and str.toUpperCase() == ' + str.toUpperCase()); //'ABC'
console.log('str == "abc" and str.indexOf(\'b\') == ' + str.indexOf('b')); //1
console.log('str == "abc" and str.indexOf(\'b\') == ' + str.indexOf('x')); //-1
