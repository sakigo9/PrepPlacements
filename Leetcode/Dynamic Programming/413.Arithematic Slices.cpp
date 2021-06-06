class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        int ans=0;
        for(int i=2;i<dp.size();i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
                ans+=dp[i];
            }
        }
        return ans;
    }
};