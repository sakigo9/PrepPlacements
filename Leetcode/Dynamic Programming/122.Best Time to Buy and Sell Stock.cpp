class Solution {
public:
    int maxProfit(vector<int>& p) {
        int start=0;
        int end=0;
        int res=0;
        for(int i=1;i<p.size();i++){
           if(p[i]>=p[i-1]){
               end++;
           }
               else{
               res+=p[end]-p[start];
               start=end=i;
               }
           
        }
        res+=p[end]-p[start];
        return res;
    }
};