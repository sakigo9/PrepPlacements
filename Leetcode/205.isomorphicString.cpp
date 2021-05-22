#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,vector<int>> m1,m2;
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);
            if(m1[s[i]]!=m2[t[i]]) return false;
        }
       
        return true;
    }
};