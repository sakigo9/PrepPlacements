// count and count_if are applicable for vector , map

#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
bool isEven(int i)
{
    if (i % 2 == 0)
        return true;
    else
        return false;
}
int main()
{
    vector<int> v{2,1,-3,5,3,9,-7,2,8,-4};
    int target=2;
    cout<<count(begin(v),end(v),2)<<endl;
    int odds;
    odds=count_if(begin(v),end(v),isEven);
    int even=count_if(begin(v),end(v),[](auto e){ return e%2!=0;}); // used for C++17
    cout<<odds;
    cout<<endl<<even;
    
}
