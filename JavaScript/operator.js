//right shift with zero fill
console.log((0b11111>>>1).toString(2));
console.log((-3>>>0).toString(2));

//new and delete
var objectName = new Date();
console.log(objectName);
delete objectName;
console.log(objectName);

//typeof
var n = 1;
console.log(typeof n);

//in
var trees = ["redwood", "bay", "cedar"];
console.log(0 in trees);
console.log(4 in trees);

//instanceof
var theDay = new Date();
if (theDay instanceof Date) {
  console.log('theday is an instance of Date');
  console.log(theDay);
}

//spread operator
var parts = ['shoulder', 'knees'];
var lyrics = ['head', ...parts, 'and', 'toes'];
console.log(lyrics);

function f(x,y,z) { console.log(arguments);}
var args = [0, 1, 2];
f(...args);
