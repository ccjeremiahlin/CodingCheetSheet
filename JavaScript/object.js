var jane = {
  name: 'Jane',
  describe: function() {
    'use strict';
    return 'Person named '+this.name;
  }
};
console.log(jane.name);
jane.newProperty = 'abc';//assign new property on the fly
console.log(jane.newProperty);//'abc'
delete jane.newProperty;
console.log(jane.newProperty);//undefined

//arbitrary property keys

var obj = { 'not an identifier' : 123} ;
console.log(obj['not an identifier']);//'123'

//nested function inside a method cannot access this. need workaround
//1. explicitly define a different var inside the function, then nested one can access it.
var jane = {
  name: 'Jane',
  friends: ['john', 'mark'],
  logHiToFriends: function() {
    'use strict';
    var that = this;
    this.friends.forEach(function (friend){
      console.log(that.name+' says hi to '+friend);
    });
  }
}
jane.logHiToFriends();
//2. passing this as a parameter

var joane = {
  name: 'Joane',
  friends: ['john', 'mark'],
  logHiToFriends: function() {
    'use strict';
    this.friends.forEach(function (friend){
      console.log(this.name+' says hi to '+friend);
    }, this);
  }
}

joane.logHiToFriends();

//constructor

function Point(x, y) {
  this.x = x;
  this.y = y;
}

Point.prototype.dist = function() {
  return Math.sqrt(this.x*this.x + this.y*this.y);
}

var p = new Point(3, 5);
console.log(p.dist());
console.log(p instanceof Point);

//getter and setter

var o = {
  a: 7,
  get b() { return this.a+1;},
  set c(x) {  this.a = x/2; }
};

o.c=10;
console.log(o.b);

var O = {a:0};
Object.defineProperties(o, {
  "b": { get: function(){ return this.a+1;}},
  "c": { set: function(x){ this.a=x/2;} }
});
O.c=10;
console.log(o.b);

//inheritance
//1. without parameters
function Employee() {
  this.name = "";
  this.dept ="general";
}

function Manager() {
  Employee.call(this);
  this.reports = [];
}
Manager.prototype = Object.create(Employee.prototype);

var manager = new Manager();
console.log(manager);
//2. with parameters

function Employee_p (name, dept) {
  this.name = name || "";
  this.dept = dept || "general";
}
function WorkerBee_p (name, dept, projs) {
  Employee_p.call(this, name, dept);
  this.projects = projs || [];
}
WorkerBee_p.prototype = new Employee;
var worker = new WorkerBee_p("W", "Workerr", [1, 2]);
console.log(worker);
