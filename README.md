# Tensor Language
## Features
#### Data Type
- [ ] si8/ui8
- [ ] si16/ui16
- [ ] si32/ui32
- [x] si64/ui64
- [ ] fp32
- [x] fp64
- [x] str

#### Statement
- [x] assignment statement
- [x] declaration statement
- [x] if else statement
- [x] slice expression
- [x] + - * / 

#### Display
![image](https://github.com/muzhailong/tl/raw/master/results/1.png?raw=true)

#### Usage
./tl test.tl --dump_ast --ast_file 1.dot --dump_mlir --mlir_file mlir.txt

#### MLIR
source code:
<pre>
si64[32,20] self_add(si64 a,si64 b,si64[22,32]c){
    return a + b * c;
}
</pre>
MLIR:
<pre>
"builtin.module"() ({
  "tl.func"() ({
  ^bb0(%arg0: tensor<1xsi8>, %arg1: tensor<1xsi8>, %arg2: tensor<22x32xsi8>):
    %0 = "tl.mul"(%arg1, %arg2) : (tensor<1xsi8>, tensor<22x32xsi8>) -> tensor<*xf64>
    %1 = "tl.add"(%arg0, %0) : (tensor<1xsi8>, tensor<*xf64>) -> tensor<*xf64>
    "tl.return"(%1) : (tensor<*xf64>) -> ()
  }) {function_type = (tensor<1xsi8>, tensor<1xsi8>, tensor<22x32xsi8>) -> tensor<32x20xsi8>, sym_name = "self_add"} : () -> ()
}) : () -> ()
</pre>