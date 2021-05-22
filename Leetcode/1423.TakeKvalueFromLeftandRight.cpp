#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
     
    int maxScore(vector<int>& c, int k) {
        int rsum[k+1],lsum[k+1];
        int n=c.size();
        rsum[0]=lsum[0]=0;
        for(int i=1;i<=k;i++){
            lsum[i]=lsum[i-1]+c[i-1];
        }
        for(int i=1;i<=k;i++){
            rsum[i]=rsum[i-1]+c[n-i];
        }
        
        int res=0;
        for(int i=0;i<=k;i++){
           res=max(res,lsum[i]+rsum[k-i]);
        }
        return res;
    }
};