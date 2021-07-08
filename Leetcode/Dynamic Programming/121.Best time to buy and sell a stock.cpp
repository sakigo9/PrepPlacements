class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res=0;
        int m=INT_MAX;
        for(int i=0;i<p.size();i++){
            m=min(p[i],m);
            res=max(res,p[i]-m);
        }
        return res;
    }
};