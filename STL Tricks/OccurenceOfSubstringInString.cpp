// string find
// Returns index
#include <iostream>
#include<string>

using namespace std;

int main()
{
    // 1. finding string from a string
    string s1="helloll";
    string s2="ll";
    size_t f=s1.find(s2);
    if(f!=string::npos){
        cout<<f<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    // 2. Second occurence
    f=s1.find(s2,f+1);
    if(f!=string::npos){
        cout<<f<<endl;
    }
}
