#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	if(s.empty()){
		cout<<"0";
	}
	int c=0;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]==' ' && c==0){
			continue;
		}
		else if(s[i]==' ' && c!=0){
			break;
		}
		else{
			c+=1;
		}
	}
	cout<<c;
}
