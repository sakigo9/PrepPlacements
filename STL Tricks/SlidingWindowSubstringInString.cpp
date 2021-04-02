#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        int a[2];
        int c=0;
        for(int i=0;i<2;i++){
            cin>>a[i];
        }
        string s="a*b**c";
       // cin>>s;
        int k=a[1];
        if(k>a[0]){
            cout<<"NO";
            break;
        }
        
        for(int i=0;i<a[0]-k+1;i++){   // N-K+1
                // K
                string s1(k,'*');
                string s2=s.substr(i,k);
                
            
            if(s1==s2){
                c=1;
                break;
                
            }
            else{
               continue;
            }
        }
        
        if(c!=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}




// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;cin>>n;
//     while(n--){
//         int a[2];
//         int c=0;
//         for(int i=0;i<2;i++){
//             cin>>a[i];
//         }
        
//         string s;
//         cin>>s;
//         int k=a[1];
//         if(k>a[1]){
//             cout<<"NO"<<endl;
            
//         }
//         string s1(k,'*');
//         size_t o=s.find(s1);
//         if(o!=string::npos){
//             c=1;
//         }
//         else{
//             c=0;
//         }
        
//         if(c!=0){
//             cout<<"YES"<<endl;
//         }else{
//             cout<<"NO"<<endl;
//         }
//     }
// }