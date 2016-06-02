
//primitive values: Boolean, Numbers (64), Stirngs, undefined, null
var yesorno = false;
var number = 1234567890;
var str = 'lalala';

//arithmatic on NaN still gets a NaN
var nan = NaN-1;
console.log(nan);
console.log();

//same thing with infinity
var ifi = Infinity-1;
console.log(ifi);
console.log();

//compare NaN to Nan, Infinity to Infinity
console.log('NaN==Nan? ' + (nan==nan).toString()); //false
console.log('Infinity==Infinity? ' + (ifi==ifi-1).toString()); //false
console.log();

//compare null==undefined, and 0/false/""
console.log('null==undefined? ' + (null==undefined).toString());//true
console.log('null==0? ' + (null==0).toString());//false
console.log('null==fale? ' + (null==false).toString());//false
console.log('but !null is ' + (!null).toString()); //true
console.log('and !undefined is also ' + (!undefined).toString()); //true
console.log();

//compare false, "", 0,  to each other, using  ==
console.log('false==0? ' + (false==0).toString()); //true
console.log('""==false? ' + (""==false).toString()); //true
console.log('0==""? ' + (0=="").toString()); //true
console.log();
//compare false, "", 0,  to each other, using  ===
console.log('false===0? ' + (false===0).toString()); //true
console.log('""===false? ' + (""===false).toString()); //true
console.log('0===""? ' + (0==="").toString()); //true
console.log();

//each object has unique identity
var obj1 = {}
var obj2 = {}
console.log('obj1===obj2? ' + (obj1===obj2).toString());//false
console.log('obj1===obj1? ' + (obj1===obj1).toString());//true

var prim1 = 123;
var prim2 = 123;

console.log('prim1===prim2? ' + (prim1===prim2).toString());//true
console.log('3 === 3? ' + (3===3).toString()); //true
console.log('abc===abc? ' + ('abc'==='abc').toString()); //true

//Objects
//1. Plain objects
var obj = {}; //empty obj
var withproperties = {
                       firstName: 'Jane',
                       lastName: 'Doe',
                     };

console.log(obj);
console.log(withproperties);
console.log('First Name: '+withproperties.firstName)
console.log('Last Name: '+withproperties.lastName)
console.log();

//2. Array

var ary = ['apple', 'banana', 'cherry'];
console.log(ary);

//3. Regular expression

var rex = /^a+b+$/
console.log(rex)

//Wrapper Types
//String.prototype, Boolean.prototype, Number.prototype

//Categorizing values via typeof and instanceof
console.log(typeof true);//boolean
console.log(typeof 'abc');//string
console.log(typeof {}); //object
console.log(typeof []); //object

var b = new Bar();
console.log(b instanceof Bar);
