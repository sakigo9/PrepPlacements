#include<iostream>
using namespace std;
int getBit(int n,int pos){    // and used
    return ((n&(1<<pos))!=0);
}

int setBit(int n,int pos){    // or used 
    int mask=1<<pos;
    return mask|n;
}

int clearBit(int n,int pos){
    int mask=1<<pos;
    mask=~mask;
    return mask&n;
}

int updateBit(int n,int pos,int val){
    int mask=~(1<<pos);
    n=n&mask;
    return n| val<<pos;
}
int main(){ 
   cout<<getBit(5,2)<<endl;        // 1010-> index 0123 -->1
   cout<<setBit(5,1)<<endl;        //7
   cout<<clearBit(5,2)<<endl;      // 1
   cout<<updateBit(5,2,1)<<endl;   // 5
  
}