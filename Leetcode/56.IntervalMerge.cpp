#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {  
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
      //  cout.tie(NULL);
        vector<vector<int>>ans;  
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end()); 
        int f=intervals[0][0]; 
        int e=intervals[0][1]; 
        for(int i=0;i<intervals.size();i++)
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

    // Method 2

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(output.back()[1] >= intervals[i][0]) output.back()[1] = max(output.back()[1] , intervals[i][1]);
            else output.push_back(intervals[i]); 
        }
        return output;
    }

    //method 3(some error but easy)
      vector<vector<int>> merge(vector<vector<int>>& inte) {
        vector<vector<int>> res;
        if(inte.size()<=0) return res;
        vector<int> part=inte[0];
        sort(begin(inte),end(inte));
        for(auto i:inte){
            if(i[0]<=part[1]){
                part[1]=max(i[1],part[1]);
            }else{
                res.push_back(part);
                part=i;
            }
            
        }
        res.push_back(part);
        return res;
    }