#include<iostream>
using namespace std;
void selectionSort(int A[],int n){
	
	for(int i=0;i<n-1;i++)  //We need to do n-2 passes as the last two will be already sorted
	{
		int iMin=i;          // take first index
		for(int j=i+1;j<n;j++){   //for loop for getting the Min value at starting
			if(A[j]<A[iMin]){
				iMin=j;        //updated index of minimum element
			}
			
		}
		int temp=A[i];
			A[i]=A[iMin];
			A[iMin]=temp;
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
	
	selectionSort(A,n);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
	
//	Time Complexity = O(n*2)
//  Slow Sorting Algorithm
}
