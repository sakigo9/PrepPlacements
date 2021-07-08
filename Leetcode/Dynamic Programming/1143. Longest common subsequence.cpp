class Solution {
public:
    int longestCommonSubsequence(string w1, string w2) {
        
        int n1=w1.size();
        int m1=w2.size();
        vector<vector<int>> dp(n1+1,vector<int>(m1+1,0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=m1;j++){
                if(w1[i-1]==w2[j-1]) // value same
                  dp[i][j]=dp[i-1][j-1]+1; //diagonal element + 1
                else
                  dp[i][j]=max(dp[i][j-1],dp[i-1][j]); // different then max of them
            }
        }
        return dp[n1][m1];
    }
};