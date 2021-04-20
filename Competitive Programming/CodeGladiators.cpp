/* Read input from STDIN. Print your output to STDOUT*/
#include<iostream>
using namespace std;
bool check(string s2, string s1){
    int n=s1.size();
    int m=s2.size();
    if(s1==s2) return true;
    int j=0;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[j]){
            j++;
        }
        if(j==m){
            return true;
        }
    }
    return false;
}
int main()
{
    string s1; cin>>s1;
    int n; cin>>n;
    vector<string> s2;
    for(int i=0;i<n;i++){
        string s3;
        cin>>s3;
        s2.push_back(s3);
    }
    for(int i=0;i<s2.size();i++){
        if(check(s2[i],s1)){
            cout<<"POSITIVE"<<endl;
        }
        else{
            cout<<"NEGATIVE"<<endl;
        }
    }
}
