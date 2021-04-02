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
        
        string ="a*****basdfg";
        //cin>>s;
        int k=a[1];
        int m=0;
        for(int i=0;i<a[0];i++){
            if(s[i]=='*'){
                c++;
                if(c>m){
                    m=c;
                }
            }
            else{
                c=0;
            }
        }
        if(m>=k){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}