// two pointer technique
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <iostream>

using namespace std;

int main()
{
    int A[]={-12, 11,9, -13, -5,6, -7, 5, -3, 11};
    int n=sizeof(A)/sizeof(A[0]);
    int s=0;
    int e=n-1;
    while(e>=s){
        if(A[s]<0 && A[e]<0){  //either both end values are -
            s++;
            
        }
        else if(A[s]>0 && A[e]<0){ //either both end values are of diff sign
            swap(A[s],A[e]);
            s++;
            e--;
        }
        else if(A[s]>0 && A[e]>0){ //both are +
            e--;
        }
        else{                       // normal incr
            s++;
            e--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    
}
