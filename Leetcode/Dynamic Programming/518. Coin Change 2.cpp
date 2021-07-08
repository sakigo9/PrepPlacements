// TC: O(coins*amount)
// SC: 2D matrix size(coins*amount)
class Solution {
public:
    int change(int m, vector<int>& coins) {
       int n=coins.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=0;
                }else if(j==0){
                    dp[i][j]=1;
                }else if(coins[i-1]<=j){ //include
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j]; //exclude
                }
            }
        }
        return dp[n][m];  
    }
};

//optimizing space
// SC: O(amount+1)
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> target_arr(amount+1,0);
		//there is one way to make 0 amount,which is 0 no of all coins
		target_arr[0]=1;
		for(int coin : coins)
		{
			for(int i=coin;i<=amount;i++)
				target_arr[i]+=target_arr[i-coin];
		}
		return target_arr[amount];
	}
};