/**
 * Created by James on 23/08/2016.
 */
var addone = require('./build/Release/addone');

var res = addone.addone(1.1);
console.log('res', res);

var ta = new Float64Array(4);
ta.fill(1);

var ta2 = new Float64Array([1,20,300, 4000]).subarray(1,3);
console.log('ta2', ta2);

var res2 = addone.addone_ta_f64(ta2);
console.log('res2', res2);

var is_Float32Array = res2 instanceof Float32Array;
var is_Float64Array = res2 instanceof Float64Array;

var i32a = new Int32Array([1, 20, 300, 4000]).subarray(1,3);
console.log('i32a', i32a);
var res_i32a = addone.addone_ta_i32(i32a);
console.log('res_i32a', res_i32a);


console.log('is_Float32Array', is_Float32Array);
console.log('is_Float64Array', is_Float64Array);