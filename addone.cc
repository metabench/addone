// hello.cc
#include <node.h>
#include "addone_inner.cc"

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;

void Addone(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  //

  double res = addone(args[0]->NumberValue());
  args.GetReturnValue().Set(Number::New(isolate, res));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "addone", Addone);
}

NODE_MODULE(addone, init)

}  // namespace demo