#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
       return (n <= 0) ? 0 : !(n & (n - 1));
    }
};