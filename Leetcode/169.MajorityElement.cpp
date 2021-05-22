#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0;
        int c=0;
        for(auto i:nums){
            if(c==0){
                majority=i;
                c++;
            }else if(i == majority){
                c++;
            }else{
                c--;
            }
        }
        return majority;
    }
};
