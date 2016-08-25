// hello.cc
#include <node.h>
#include "addone_inner.cc"
#include <iostream>

using namespace std;

namespace simple {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;
using v8::Handle;

void Addone(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  //

  double res = addone(args[0]->NumberValue());
  args.GetReturnValue().Set(Number::New(isolate, res));
}

void Addone_TA(const FunctionCallbackInfo<Value>& args) {

  const double *x = reinterpret_cast<double*>(args[0].As<v8::Float64Array>()->Buffer()->GetContents().Data());
  int l = sizeof(*x);
  cout << "Length of array = " << (l) << endl;

  double* res = new double[l];

  for (int c = 0; c < l; c++) {
    res[c] = x[c] + 1;
  }

  //v8::Handle<v8::JSTypedArray> typed_array;

  // Outputting a new typed array...

  //args.GetReturnValue().Set(
  //		v8::Float64Array::New(args.GetIsolate(), res)
  //	);






}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "addone", Addone);
  NODE_SET_METHOD(exports, "addone_ta", Addone_TA);
}

NODE_MODULE(addone, init)

}  // namespace simple