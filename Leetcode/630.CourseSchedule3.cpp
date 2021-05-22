#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
/*

                    HARD

Time Complexity: O(N * log N) where N is the length of C, due to both the sort and the priority queue / heap implementation
Space Complexity: O(N) due to the priority queue / heap data


*/

    int scheduleCourse(vector<vector<int>>& C) {
        sort(begin(C),end(C),[]( auto a,auto b){ return a[1]<b[1];}); // sort as we need less lastDate at start
        priority_queue<int> pq;
        int res=0;
        for(auto i:C){
            if(res+i[0]<=i[1]){                     //compare duration<=lastDate
            res+=i[0];                              //store C[0] in res
            pq.push(i[0]);                          // push valid case in pq
          }else if(!pq.empty() && pq.top()>i[0]){   // for optimal case
                int x=pq.top();
                pq.pop();
                res-=x;
                res+=i[0];
                pq.push(i[0]);
            }
        }
        return pq.size();
    }
};