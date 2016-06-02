function throwException() {
  throw new Error('Problem!');
}

try {
  throwException();
} catch (e) {
  console.log(e);
  //console.log(e.stack);
}
