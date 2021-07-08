class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n== 0 || m == 0) return 0; // base case
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp vector
        int max_ =0; // to store max value
        for(int i=1; i<=n; i++){
            for(int j =1; j<=m; j++){
               
                if(nums1[i-1] != nums2[j-1]){
                    dp[i][j] =0; 
                }
                else{ // nums1[i-1] == nums2[j-1]
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                if(dp[i][j] > max_) max_ = dp[i][j]; //update max value
            }
        }
        return max_;
    }
};