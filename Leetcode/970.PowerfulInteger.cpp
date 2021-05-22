#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        set<int> p;   // set to avoid duplicate element
        
        for (size_t i = 1; i <= bound; i *= x)   // taking all square values possible for x
        {
            for (size_t j = 1; i + j <= bound; j *= y)   // taking all square values possible for y
            {
                p.insert(i + j);
                
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        
        return vector(p.begin(), p.end());    //assigning set to vector
    }
};