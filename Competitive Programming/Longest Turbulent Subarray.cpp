#include<bits/stdc++.h>
using namespace std;
int Turbulent(int a[],int n){
	int high=0;
	int low=0;
	for(int i=0;i<n;i++){
		if (i>=2 and (a[i-2]>a[i-1]<a[i] or a[i-2]<a[i-1]>a[i])){
			low+=1;
		}
		else if (i>=1 and a[i-1]!=a[i]){
			low=2;
		}
		else{
			low=1;
		}
			
	high=max(low,high);
	}
	return high;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	cout<<"Length"<<Turbulent(a,n);
}
