i64[32,20] add(i64 a,i64 b){
    return a+b;
}

fp64[32,28,28] equal(fp64 [32,28,28]a,fp64 [32,28,28]b){
    return a==b;
}

i65 main(){
    i64 [32,20] a;
    i64 [32,30] b;
    i64 c = add(a,b);
    return c;
}