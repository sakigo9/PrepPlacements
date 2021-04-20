#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; 

// function to find minimum number of increment (by 1) operations to make the array in increasing order. 

//first method
int Minimum_Moves(vector<int> &a, int n) 
{ 
    // to store answer 
    int count = 0;
    // iterate over the vector container array 
    for (int i = 1; i < n; i++) 
    { 
    // if in non- increasing order 
        if (a[i] <= a[i - 1]) 
        { 
            int p = (a[i - 1] - a[i]) + 1 ; 

            // add moves to answer 
            count += p; 
            // increase the element by 1 
            a[i] += p ; 
        } 
    } 
    // return required answer 
    return count; 
} 
//second method
int Minimum_Moves(vector<int> &nums, int n) 
{ 
    
    int count=0;
    for(int i=0;i<nums.size();i++){
        int target=max(nums[i],nums[i-1]+1);
        count+=target-nums[i];
        nums[i]=target;
    }
   
    return count; 
} 

// Driver code 
int main() 
{ 
    vector<int> arr ;
  	int n,a;
  	cin>>n;
    for(int i=0;i<n;i++)
    {
          
            cin>>a;
            arr.push_back(a);
    } 
    cout << Minimum_Moves(arr, n); 
    return 0; 
} 
