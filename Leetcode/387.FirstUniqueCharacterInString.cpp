
#include <iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
    string s="sakets";
    int freq[264]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]]==1){
                cout<<i;
                
            }
}
         cout<<"-1"<<endl;;   
         
         // 2nd solution
         cout<<"unordered_map"<<endl;
         unordered_map<char,int> u;
         for(auto &c:s){
             u[c]++;
         }
         for(int i=0;i<s.length();i++){
             if(u[s[i]]==1) cout<<i<<endl;
         }
         cout<<-1;
        
}
