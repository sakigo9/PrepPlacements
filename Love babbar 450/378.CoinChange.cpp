//Time Complexity : O(amount*coins array length)

class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        int n=coins.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=1e5;
                }else if(j==0){
                    dp[i][j]=0;
                }else if(coins[i-1]<=j){ //include
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j]; //exclude
                }
            }
        }
        return dp[n][m]>1e4?-1:dp[n][m];
    }
};