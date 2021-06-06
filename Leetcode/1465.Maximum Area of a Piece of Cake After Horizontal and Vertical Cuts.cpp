#include<vector>
#include<algorithm>
using namespace std;

// Time Complexity : O(HlogH + VlogV), where H is the number of Horizontal cuts and V is the number of Vertical cuts
// Space Complexity : O(1), we don't use any extra space (ignoring the space required for sort)

class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
	return long(getMaxGap(H, h)) * getMaxGap(V, w) % 1000000007;
}
int getMaxGap(vector<int>& nums, int max_size) {
	sort(begin(nums), end(nums));
	int maxGap = max(nums[0], max_size - nums.back()); // handling the case of first and last piece of cake
	for(int i = 1; i < size(nums); i++) maxGap = max(maxGap, nums[i] - nums[i - 1]);
	return maxGap;
}
};