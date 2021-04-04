// find versions

#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v{2,11,1,-3,5,3,9,-7,2,8,-4,-3,5};
    int target=2;
    string s{"Hello i am a string"};
    //type 1 find the target
    auto f=find(begin(v),end(v),target)-begin(v);                               //0
    cout<<f<<endl;
    //type 2 find first odd value
    auto f1=find_if(begin(v),end(v),[](auto e){return e%2!=0;});                //11
    cout<<*f1<<endl;
    //type 3 findif_not
    auto f2=find_if_not(begin(v),end(v),[](auto e){return e%2!=0;})-begin(v);  //0
    cout<<f2<<endl;
    // type 4 find_first_of
    vector<int> v1{-3,5,3,9,-7};
    auto f3=find_first_of(begin(v),end(v),begin(v1),end(v1));
    cout<<*f3<<endl;
    //type 5 search
    vector<int> v2{-3,5};
    auto f4=search(begin(v),end(v),begin(v2),end(v2));
    cout<<*f4<<endl;
    //type 6
    string s1="am";
    auto f5=search(begin(s),end(s),begin(s1),end(s1))-begin(s);
    cout<<f5<<endl;
    
    
}
