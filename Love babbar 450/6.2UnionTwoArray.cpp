// Time Complexity : O(logN)+O(1)==O(logN)
#include <iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;

int main()
{
	vector<int> a={1,2,4,5,9};
	vector<int> b={3,4,6,7,8,10};
	unordered_set<int> a1(a.begin(),a.end());    //O(1)
	unordered_set<int> a2(b.begin(),b.end());    //O(1)
	set<int> us;                                 //O(logN)
	for(auto i:a1){
	    if(a2.count(i)!=1){                     // count only works for unordered_set
	        us.insert(i);
	    }
	}
	for(auto i:a2){
	    if(a1.count(i)!=1){
	        us.insert(i);
	    }
	}
	for(auto j:us){
	    cout<<j<<" ";
	}
}
