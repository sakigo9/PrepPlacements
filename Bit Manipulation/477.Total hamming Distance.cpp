class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size(),sum=0;
		for(int i=0;i<32;i++){
            int num = 1<<i;
            int ones=0,zero=0;
            
            for(int j=0;j<n;j++){
                if(nums[j]&num){
                    ones++;
                    
                }else{
                    
                    zero++;
                }
            }
            
            if(ones==n||zero==n){
                continue;
            }else{
                sum += (ones*zero);
            }
        }    
        return sum;
		}
	};