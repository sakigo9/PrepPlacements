
#include<iostream>

using namespace std;
int Dslide(int n){
    int a[4]={20,36,51,60};
    int b[4]={16,32,44,55};
    int res=0;
    int k=n%4;
    if(n<=4){
        res+=a[n-1];
    }
    else{
       res=abs((n-k)/4)*44+b[k];
      // res+=b[k];
    }
    return res;
}
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<Dslide(n)<<endl;
    }
}
