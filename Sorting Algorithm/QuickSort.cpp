// pivot is always the last element even for partition
//Divide and Conquer algo
//Uses Recursive Call
//Time	Complexity,	T(n)=O(nlogn). [Best + Average Case]
// Worst	case	Complexity:	O(n2)
//Elements at left is less than pivot and elements at right is greater than pivot
#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int Partition(int *A,int start,int end){
	int pivot = A[end];    //making rightmost as pivot
	int pindex=start;
	for(int i=start;i<end;i++){
		if(A[i]<pivot){     //checking values less than pivot and swapping them to left
			swap(A[i],A[pindex]);
			pindex++;
		}
	}
	swap(A[pindex],A[end]); // updating pivot by swapping previous pivot to its correct place
	return pindex;
}
void QuickSort(int *A,int start,int end){
	if(start<end){
		int pindex=Partition(A,start,end);
		QuickSort(A,start,pindex-1);
		QuickSort(A,pindex,end);
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
	
	QuickSort(A,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
	

}
