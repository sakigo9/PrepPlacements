
#include <algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> nums={1,3,4,5};
    int n=nums.size();
    int target=0;
    auto lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    cout<<lb;
    
}
