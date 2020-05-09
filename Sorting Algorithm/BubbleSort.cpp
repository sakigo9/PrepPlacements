

//	Time Complexity = O(n*2)
//  Slow Sorting Algorithm

#include<iostream>
using namespace std;
void BubbleSort(int A[],int n){
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1]){
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
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
