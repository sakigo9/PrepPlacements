// find and erase takes address as parameters
//using iterator makes it easy for traversal
// find returns it
#include <algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> nums={2,3,1,2,0,4};
    int n=nums.size();
    int val=2;
    vector<int>:: iterator i=nums.begin();  // this iterator moves to entire array
    while(i!=nums.end()){
        vector<int>:: iterator j;           // this iterator is to find val address 
    j=find(nums.begin(),nums.end(),val);
    cout<<" val "<<j-nums.begin()<<endl;
    if(j!=nums.end()){
        nums.erase(j);
    }else{
        i++;
    }
    
    }
    cout<<nums.size();
}
