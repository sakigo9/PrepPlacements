#include<algorithm>
#include<queue>
#include<iostream>
#include <numeric>
using namespace std;
class Solution {
public:
    
    //uses a heap and has O(n log n) time complexity.
    
    
    bool isPossible(vector<int>& target) {
        
    auto s = accumulate(begin(target), end(target), (long long)0);
        
    priority_queue<int> q(begin(target), end(target));
        
    while (s > 1 && q.top() > s / 2) { //If the largest element is smaller than s / 2, we cannot continue with our turns.
        
        auto cur = q.top(); q.pop();
        s -= cur;
        
        if (s <= 1)
            return s;
        q.push(cur % s);//In case the largest element is significantly bigger than the sum of other elements, we can get TLE. To counter that, we can use modulo operation (as in 780. Reaching Points). Instead cur - (s - cur), we will do cur % (s - cur)
        s += cur % s;
    }
    return s == target.size();
}
};
/*

bool isPossible(vector<int>& target) {
	if(size(target) == 1) return target[0] == 1;
	priority_queue<int> pq(begin(target), end(target));
	long sum = accumulate(begin(target), end(target), 0l);
	while(pq.top() != 1) {       // repeat till all elements haven't been made equal to 1
		long largest = pq.top(); pq.pop();
		long largest_2 = pq.top(), restArrSum = sum - largest;

		// n = number of subtraction to get largest below 2nd largest element. max(1, ..) denotes teh case where largest and largest_2 are equal
        int n = max(1l, (largest - largest_2) / restArrSum);
        
		largest -= (restArrSum * n); // subtracting from largest n times till it gets lower than 2nd largest
		
		 The above apporach was the first intuition I got & slightly easier to get
		*  We can do it using modulo as well(although it requires some extra conditional checks) by replacing the above 2 lines with -
		*   if(restArrSum == 1) return true;
        *   if(restArrSum == 0 || largest <= restArrSum) return false;
        *   largest %= restArrSum;
		
		pq.push(largest);            // push the modifed element back in
		sum = restArrSum + largest;  // update the sum of array
		if(largest < 1) return false;// if an element gets below 1, we cant achieve original array
	}
	return true;
}
*/


