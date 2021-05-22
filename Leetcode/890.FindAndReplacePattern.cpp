#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
class Solution {
public:

    // Complexity: O(M*N) M: Length of single word  N:Number of words

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        vector<string> ans;
        int flag;
        for(string s:words){
         
            flag = 0;
            map1.clear();
            map2.clear();
            for(int i = 0; i<s.length(); i++){
                    if(!map1[s[i]] && !map2[pattern[i]]){     // if map is doesnt have s[i] or pattern[i] then add
                        map1[s[i]]=pattern[i];
                        map2[pattern[i]]=s[i];
                    }else if(map1[s[i]]==pattern[i] && map2[pattern[i]]==s[i]){  // check if existing same char are matching then continue
                        continue;
                    }
                else{
                    flag = 1;  // char from both doesnt matches
                    break;
                }
            }
            if(flag == 0){
                ans.push_back(s);
            }
            
            
        }
        return ans;
    }
};