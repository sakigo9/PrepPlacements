
#include<iostream>
#include<algorithm>
using namespace std;
string reverseStr(string s, int k) {
        int n=s.size();
        int l=2*k;
        for(int i=0;i<s.size();i+=l){
            if(n<k){
                reverse(begin(s)+i,end(s));
            }else{
                reverse(begin(s)+i,begin(s)+i+k);
                n-=l;
            }
            
        }
        return s;
    }
int main()
{
    string k=reverseStr("abcdefg",2);
    //cout<<k;

}
