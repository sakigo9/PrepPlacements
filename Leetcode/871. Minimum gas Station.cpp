

//Time Complexity : O(logN)
// Max Heap-> Priority Queue

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //we use priority queue (max heap ) to store the capacities of the gas station 
        priority_queue<int> pq; 
        int curr=startFuel;
        int i=0; //a index value of stations which represents the  station which we starting adding capacties from
        int res=0; //the result 
        while(curr<target)
        {
		   //we push the gas station capacities until the curr position into the max heap
		 while(i<stations.size() && stations[i][0]<=curr){
                pq.push(stations[i][1]); // push the capacities
                i++;
            }
			
            //we are at position curr 
			//and i have no gas now so,
            //now i will look behind and i pick the gas station which has more capacity
            //why more capacity gas station ?  since it is the better option as i can traverl much longer
            
         
           
            if(pq.empty())
            {
                //there is no gas station we can refill
                return -1;
            }
            //pick the station with max capacity 
            //and add it to the curr position since we travel by using the gas to some position
            curr+=pq.top();
            res++; //as you have used one station 
            pq.pop(); //dont use the station again
        }
        return res;
    }
};