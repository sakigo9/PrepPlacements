#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0]=0;
        
        for(int i=1;i<=num;i++){
            res[i]=res[i/2]+i%2;
        }
        return res;
    }
};