#include<iostream>

using namespace std;
int power(long long x, unsigned int y, int p)
{
    int res = 1;     
 
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p=pow(10,9)+7;
        cout<<power(2,n-1,p)<<endl;
    }
}