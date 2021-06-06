
// Bottom up approach
// Time: n*n^1/2
// Space:n
class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int sq=1; sq<=n; sq++) {
            // sq is the current number to be checked
            for(int i=1; i*i<=sq; i++) {
                dp[sq] = min(dp[sq], dp[sq-(i*i)]+1);
            }
        }
        return dp[n];
    }
};

// Top down approach

class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = INT_MAX;
        for(int i=1; i*i<=n; i++) {
            dp[n] = min(dp[n], solve(n-(i*i), dp)+1);
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector <int> dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};