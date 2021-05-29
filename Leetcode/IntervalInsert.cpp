#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;




class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ne) {
        intervals.push_back(ne);
        vector<vector<int>>ans;  
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end()); 
        int f=intervals[0][0]; 
        int e=intervals[0][1]; 
        for(int i=1;i<intervals.size();i++)
        {
            int f2=intervals[i][0]; 
            int e2=intervals[i][1]; 
            if(max(f,f2)<=min(e,e2))//overlapping happens here
            {
                f=min(f,f2); 
                e=max(e,e2);
            } 
            else
            {
                ans.push_back({f,e}); 
                f=f2; 
                e=e2;
            }

        } 
        ans.push_back({f,e});
        return ans;
    }
};