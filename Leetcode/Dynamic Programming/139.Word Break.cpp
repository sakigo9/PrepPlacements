
// 1D array DP 
//TC : O(n^2)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i < n+1; ++i){
            for (int j = 0; j < wordDict.size(); ++j){
                if (dp[i-1] && s.substr(i-1, wordDict[j].size()) == wordDict[j]) // takes n calls
                    dp[i+wordDict[j].size()-1] = 1;
            }
        }
        return dp[n];
    }
};

//Recursion
// TC: O(n^2) SC: O(n)
//TLE
class Solution {
public:
    //Time: O(2^N), Space: O(N)
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
            return true;
        
        for(int i=1; i<=s.length(); i++){
            string prefix = s.substr(0, i);
            
            //finding the prefix in the wordDict
            auto it = find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end();
            
            //check for the remaining portion of string
            if(it && wordBreak(s.substr(i), wordDict))
                return true;
        }
        return false;
    }
};

// TC: O(n^3)
//TLE

class Solution {
public:
    unordered_map<string,int> dp;
    int helper(string s,vector<string> w){
        int n=w.size();
        if(n==0) return 1;
        if(dp[s]!=0){
            cout<<dp[s]<<endl;
            return dp[s];
        }
        for(int i=0;i<=n;i++){
            int f=0;
            string sub=s.substr(0,i);
            for(int j=0;j<w.size();i++){
                if(sub.compare(w[j])==0){
                    f=1;
                    break;
                }
             if(f==1 && helper((s.substr(i,n-i)),w)==1) return dp[s]=1;
            }
        }
        return dp[s]=-1;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n=helper(s,w);
        if(n==1) return true;
        else return false;
        
    }
};