

//	Time Complexity = O(n*2)
//  Slow Sorting Algorithm
// After first iteration the largest number in array gets sorted
// Sorting from bottom to top
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int A[],int n){
	int flag;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1]){
				flag=1;
				swap(A[j],A[j+1]);
			}
		}
		if(flag==0)
			break;
	}
}
	

int main(){
	int A[100];
	int n;
	cout<<"Enter the number of elements in arry"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	
	BubbleSort(A,n);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
	

}
