// hello.cc
#include <node.h>
#include "addone_inner.cc"
#include <iostream>
//#include <cstddef>

using namespace std;

namespace simple {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;
using v8::ArrayBuffer;

void Addone(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  double res = addone(args[0]->NumberValue());
  args.GetReturnValue().Set(Number::New(isolate, res));
}

void Addone_TA_F64(const FunctionCallbackInfo<Value>& args) {
  // Get the input values, accounting for subarrays
  v8::Local<v8::Float64Array> fa_input = args[0].As<v8::Float64Array>();
  int l = fa_input -> ByteLength() / sizeof(double);
  void *data = fa_input->Buffer()->GetContents().Data();
  size_t offset = fa_input->ByteOffset();
  double *x = reinterpret_cast<double*>(static_cast<unsigned char*>(data) + offset);
  double* res = new double[l];

  // Inner processing
  for (int c = 0; c < l; c++) {
    res[c] = addone(x[c]);
  }

  // Output a new typed array
  Local<ArrayBuffer> ab = v8::ArrayBuffer::New (args.GetIsolate(), res, l * sizeof(double));
	delete[] data;
  v8::Local<v8::Float64Array> f64a_res = v8::Float64Array::New(ab, 0, l);
  args.GetReturnValue().Set(f64a_res);
}

/*
void _Addone_TA_F64(const FunctionCallbackInfo<Value>& args) {
  v8::Local<v8::Float64Array> fa_input = args[0].As<v8::Float64Array>();
  int l = fa_input -> ByteLength() / sizeof(double);

  void *data = (fa_input->Buffer()->GetContents().Data());
  size_t offset = fa_input->ByteOffset();
  unsigned char* data_offset = static_cast<unsigned char*>(data + offset);
  const double *x = reinterpret_cast<double*>(data_offset);




  void *data = fa_input->Buffer()->GetContents().Data();
  size_t offset = fa_input->ByteOffset();
  unsigned char* data_offset = static_cast<unsigned char*>(data + offset);
  double *x = reinterpret_cast<double*>(data_offset);


  //v8::Local<v8::Float64Array> array = argument.As<v8::Float64Array>();


  void *data = fa_input->Buffer()->GetContents().Data();
  size_t offset = fa_input->ByteOffset();
  //size_t data_ptr = reinterpret_cast<size_t>(data);
  //data_ptr += offset;
  //double *x = reinterpret_cast<double*>(data_ptr);


  //unsigned char *data_offset = static_cast<unsigned char*>(data) + offset;
  //double *x = reinterpret_cast<double*>(data_offset);

  double *x = reinterpret_cast<double*>(static_cast<unsigned char*>(data) + offset);


  //const double *x = reinterpret_cast<double*>
  //const double *x = reinterpret_cast<double*>(fa_input -> Buffer() -> GetContents().Data());

  //cout << "Length of array = " << (l) << endl;

  double* res = new double[l];

  for (int c = 0; c < l; c++) {
    res[c] = addone(x[c]);
  }

  // Outputting a new typed array...

  Local<ArrayBuffer> ab = v8::ArrayBuffer::New (args.GetIsolate(), res, l * sizeof(double));
	//delete[] res;
	//delete[] x;
	delete[] data;
  v8::Local<v8::Float64Array> f64a_res = v8::Float64Array::New(ab, 0, l);
  args.GetReturnValue().Set(f64a_res);
}
*/
void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "addone", Addone);
  NODE_SET_METHOD(exports, "addone_ta_f64", Addone_TA_F64);
}

NODE_MODULE(addone, init)

}  // namespace simple
