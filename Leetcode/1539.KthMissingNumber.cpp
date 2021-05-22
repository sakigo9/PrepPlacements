#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) if (a <= k) k++;
        return k;
    }
};