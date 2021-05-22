#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

                // Gready Approach

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,curr=0,farjump=0;
        for(int i=0;i<nums.size()-1;i++){
            farjump=max(farjump,i+nums[i]);
            if(i==curr){
                jumps++;
                curr=farjump;
            }
        }
        return jumps;
    }
};