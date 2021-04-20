#include <set>
#include <iterator>
#include<vector>
#include<iostream>
using namespace std;
int change(int k,multiset <int, greater <int> > v){
  int c=0;
  while(k>0){
    int f=*v.lower_bound(k);
    c+=1;
    k=k-f;
    //cout<<f<< "  "<<k<<endl;
  }
  return c;
}
int main()
{
  int n;cin>>n;
  vector<int> v;
  multiset <int, greater <int> > c{1,2,5,10,20,50,100,500,1000};
  for(int i=0;i<n;i++){
    int k;cin>>k;
    v.push_back(k);
  }
  for(auto i:v){
    cout<<change(i,c)<<endl;
  }
  
  return 0;
}