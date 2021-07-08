class Solution {
public:
    // Bottom up solution
    // TC: O(n*m)
    // SC: O(n*m)
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0){
                    dp[i][j]=i;
                }else if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                                //       insert ,        remove,       replace 
                }
                
            }
        }
        return dp[n][m];
    }
};