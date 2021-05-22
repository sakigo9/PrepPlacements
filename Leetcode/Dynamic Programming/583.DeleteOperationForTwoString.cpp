#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1=w1.size();
        int m1=w2.size();
        int dp[n1+1][m1+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=m1;j++){
                if(w1[i-1]==w2[j-1])
                  dp[i][j]=dp[i-1][j-1]+1;
                else
                  dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return m1+n1-2*dp[n1][m1];
    }
};