

class Solution {
public:

       
        //Best Time : O(nlogn)
        // Dp question


    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        for(int i=0;i<n;i++){
            int idx=upper_bound(begin(dp),end(dp),nums[i])-begin(dp);
            if(nums[i]>dp[idx-1] && nums[i]<dp[idx]){
                dp[idx]=nums[i];
            }
        }
        int res=0;
        for(int i=n;i>=0;i--){
            if(dp[i]!=INT_MAX){
                res=i;
                break;
            }
        }
        return res;
        
    }
};



class Solution {
public:

    // Time C: O(n^2)

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        int lis[n];
        for(int i=0;i<n;i++)
           lis[i] =1;
 	    for(int i=1;i<n;i++) 	
          { for(int j = 0;j<i;j++) 		
	           if(nums[i]>nums[j]&&lis[i]<lis[j]+1) 
                   lis[i]=lis[j]+1;
          } 	
 	    return *max_element(lis,lis+n); 
    }
};
