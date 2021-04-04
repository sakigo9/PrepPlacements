
#include<iostream>
#include<algorithm>
#define max(a,b) ((a>b)?a:b)
using namespace std;

int main()
{  
    int a[]={-1,-2,-3,-4};
    int n=sizeof(a)/sizeof(a[0]);
    int m,t;
    m=t=a[0];
    for(int i=1;i<n;i++){
        t=max(t+a[i],a[i]);
        m=max(t,m);
    }
    cout<<m;
}
