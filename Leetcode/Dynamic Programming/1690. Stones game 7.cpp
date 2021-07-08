// Sumit Malik example

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=stones[i];
                }
                else if(g==1){
                    dp[i][j]=max(stones[i],stones[j]);
                }else{
                    int val1=stones[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2=stones[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j]=max(val1,val2);
                }
            }
        }
        return dp[0][n-1];
    }
};

//working sample
class Solution {
public:
     int stoneGameVII(vector<int>& stones) {
      int n = stones.size();
      vector<int> prefixSum(n+1,0);
      for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i-1] + stones[i-1];

      vector<vector<int>> dp(n, vector<int>(n,0));

      for (int gap = 1 ; gap < n ; gap++ ){
        for (int i = 0, j = gap; j < n ; j++, i++){
          int start =  prefixSum[j + 1] - prefixSum[i+1];
          int end  = prefixSum[j] - prefixSum[i];
          
          dp[i][j] = max( start - dp[i+1][j] , end - dp[i][j-1]);  
        }
      }
      return dp[0][n-1];      
    }
};