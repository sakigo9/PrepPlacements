#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int knapSack(int W,vector<int> weight,vector<int> profit,int n){
 vector<vector<int>> dp(n+1,vector<int>(W+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(weight[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-weight[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    // int n;
    // cin>>n;
    // vector<int> weight(n);
    // vector<int> profit(n);
    // for(int i=0;i<n;i++){
    //     int wei;
    //     cin>>wei;
    //     weight.push_back(wei);
    // }
    // for(int i=0;i<n;i++){
    //     int pro;
    //     cin>>pro;
    //     profit.push_back(pro);
    // }
    // int W;
    // cin>>W;
    int n=3;
    int W=50;
    vector<int> weight{10,20,30};
    vector<int> profit{60,100,120};

    cout << knapSack(W, weight, profit, n);
    
}