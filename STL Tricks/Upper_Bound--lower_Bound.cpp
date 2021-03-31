// works only for a binary search 
// sorted array
// return the address
//upper_bound is a special case of lower_bound
// Time Complexity is same as Binary search O(n)
#include <algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> nums={0,1,2,2,3,0,4,2};
    int val=2;
    sort(nums.begin(), nums.end());
    auto lb = lower_bound(nums.begin(), nums.end(), val);
    auto ub = upper_bound(nums.begin(), nums.end(), val);
    cout<<*lb<<" "<<*ub<<endl;
    nums.erase(lb,ub);
    cout<<nums.size()<<endl;
    cout<<"Array lower_bound"<<endl;
    int a[5]={2,3,4,6,6};
    auto q=lower_bound(a,a+5,2)-a;  // Gives Index           0
    cout<<q<<endl;                  // No need of address    
    auto w=lower_bound(a,a+5,5);    // Gives address         6
    cout<<*w<<endl;                 // Gives value from array
    auto e=lower_bound(a,a+5,7);
    cout<<*e<<endl;                 // Address of end        32764
    
    cout<<"array upper_bound"<<endl;
    auto p=upper_bound(a,a+5,4);     // value-6
    cout<<*p<<endl;
    auto b=upper_bound(a,a+5,6)-a;   // index-5
    cout<<b<<endl;
}
