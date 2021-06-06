#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size(), m = s2.size(), sz = s3.size();
        if(n + m != sz) return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        // dp[i][j] = is it possible to form s3[0...i+j-1] from s1[0...i-1] and s2[0...j-1]
        
		// both strings empty
        dp[0][0] = true;
        
		// if s2 is empty
        for(int i = 1 ; i <= n ; i++) {
            dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
        }
        
		// if s1 is empty
        for(int j = 1 ; j <= m ; j++) {
            dp[0][j] = (s2[j-1] == s3[j-1]) && dp[0][j-1];
        }
        
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                
                bool matchI = (s1[i-1] == s3[i+j-1]) && dp[i-1][j];
                bool matchJ = (s2[j-1] == s3[i+j-1]) && dp[i][j-1];
                
                dp[i][j] = matchI || matchJ;
            }
        }

        
        return dp[n][m];
    }
};