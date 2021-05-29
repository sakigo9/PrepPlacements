#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points),[](auto &x,auto &y){return x[1]<y[1];});
        if(points.size()==0) return 0;
        int res=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                res++;
                end=points[i][1];
            }
        }
        return res;
        
    }
};