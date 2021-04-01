
#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main()
{
	vector<int> a1={4,9,5,2};
	vector<int> a2={1,4,1,8,9,3,5};
	unordered_set<int> us(a1.begin(),a1.end()); 
	vector<int> res;
	for(auto it:a2){
	    if(us.count(it)){
	        res.push_back(it);
	        us.erase(it);
	    }
	}
	for(auto h:res){
	    cout<<h<<" ";
	}
}
