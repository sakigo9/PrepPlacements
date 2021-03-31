#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s1="hello";
    string s2="ll";
    size_t f=s1.find(s2);
    if(f!=string::npos){
        cout<<f;
    }
    else{
        cout<<"Not found"<<endl;
    }
    
}
