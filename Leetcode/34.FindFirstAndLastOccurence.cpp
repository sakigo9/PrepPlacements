#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        auto ib=lower_bound(begin(nums),end(nums),target);
        if(ib!=end(nums) && *ib==target){
            v.push_back(lower_bound(begin(nums),end(nums),target)-begin(nums));
            v.push_back(upper_bound(begin(nums),end(nums),target)-begin(nums)-1);
        }else{
            v.insert(v.begin(),2,-1);
        }
        return v;
    }

    // Best Solution below

    /*
    class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            int l = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
            int r = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
            return {l, r-1};
        }else{
            return {-1,-1};
        }
    }
};*/
};