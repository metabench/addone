/**
 * Created by James on 23/08/2016.
 */
var addone = require('./build/Release/addone');

var res = addone.addone(1.1);
console.log('res', res);

var ta = new Float64Array(4);
ta.fill(1);

var res2 = addone.addone_ta(ta);
console.log('res2', res2);

var is_Float32Array = res2 instanceof Float32Array;
var is_Float64Array = res2 instanceof Float64Array;

console.log('is_Float32Array', is_Float32Array);
console.log('is_Float64Array', is_Float64Array);