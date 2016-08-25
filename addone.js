/**
 * Created by James on 23/08/2016.
 */
var addone = require('./build/Release/addone');

var res = addone.addone(1.1);
console.log('res', res);

var ta = new Float64Array(8);
ta.fill(1);

console.log('pre addone_ta');
var res2 = addone.addone_ta(ta);
console.log('res2', res2);