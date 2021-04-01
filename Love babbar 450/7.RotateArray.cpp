
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[]={6,5,4,3,2,1};
	int n=6;
	int k=3;
	reverse(arr,arr+n);
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
