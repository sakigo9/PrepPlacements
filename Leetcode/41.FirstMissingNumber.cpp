#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        sort(begin(nums),end(nums));
        for(auto i: nums){
            if(i==j){
                j++;
            }  
        }
         return j;
    }
};

/*

                        BEST METHOD

[3,1,-4,7]
at index 0 3 != nums[3-1] hence swap and the array becomes [-4,1,3,7]
now at index 0 value is negative hence neglect and move forward.
at index 1 1!=nums[1-1] hence swap now the array becomes [1,-4,3,7]
now at index 1 value is negative hence neglect and move forward.
at index 2 3==nums[3-1] the condition is true and 3 is at right position hence neglect and move forward.
at index 3 value is 7 which is greater than n hence neglect

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0 ; i<n ; i++) if(nums[i] != i+1) return i+1;
        return n+1;
    }
};

*/