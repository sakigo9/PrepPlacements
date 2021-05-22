#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()>1) return false;
        int reach=0;
        for(int i=0;i<nums.size();i++){
            if(reach<i) return false;
            else reach=max(reach,i+nums[i]);
        }
        return true;
    }
};