class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int n=piles.size();
        int s1,s2;
       for(int i=0;i<n;i++){
           if(i%2==0){
               s1+=max(piles[i],piles[n-1-i]);
           }else{
               s2+=max(piles[i],piles[n-1-i]);
           }
       }
        return s1>s2?true:false;
    }
};