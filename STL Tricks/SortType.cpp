#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v{9,1,2,6,4,-1,11,6,-6,0};
    auto v1=v;
    sort(begin(v1),end(v1));
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
    //type 2 decresing sort
    sort(begin(v1),end(v1),greater<int>());
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
    //type 3 decresing sort
    auto v2=v;
    sort(begin(v2),end(v2),[](int e1,int e2){ return e1>e2; });
    for(auto i:v2){
        cout<<i<<" ";
    }
}