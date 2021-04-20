#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int maxKsum(vector<int> &v,int n,int k){
    int s=0;
    for(int i=0;i<k;i++){
        s+=v[i];
    }
    int ans=s;
    int j=k-1;
    for(int i=n-1;i>n-k-1;i--){
       
        ans=max(ans,s-v[j]+v[i]);
        s=s-v[j]+v[i];
        j--;
    }
    return ans;
}

int main() 
{ 
    vector<int> arr ;
  	int n,a;
  	cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a;
            arr.push_back(a);
    } 
    int k;cin>>k;
    cout << maxKsum(arr, n,k); 
    return 0; 
} 
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int maxKsum(vector<int> &v,int n,int k){
    int s=0;
    for(int i=0;i<k;i++){
        s+=v[i];
    }
    int ans=s;
    int j=k-1;
    for(int i=n-1;i>n-k-1;i--){
       
        ans=max(ans,s-v[j]+v[i]);
        s=s-v[j]+v[i];
        j--;
    }
    return ans;
}

int main() 
{ 
    vector<int> arr ;
  	int n,a;
  	cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a;
            arr.push_back(a);
    } 
    int k;cin>>k;
    cout << maxKsum(arr, n,k); 
    return 0; 
} 
