#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        int a[2];
        int c=0;
        for(int i=0;i<2;i++){
            cin>>a[i];
        }
        string s,s1;
        cin>>s;
        int k=a[1];
        for(int i=0;i<k;i++){
            s1+="*";
        }
        size_t o=0;
        while((o=s.find(s1,o))!=string::npos){
            c++;
            o+=k;
        }
        cout<<c;
    }
}