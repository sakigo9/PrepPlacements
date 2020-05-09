//	In	this	algorithm,	each	iteration	removes an	element	from	the	input	data	and	inserts	it	into	the	correct	position	in	the	list	being	sorted.	
//	Time Complexity = O(n*2) worst Case
// Better than Bubble and Selection Sort algo

#include<iostream>
using namespace std;
void InsertionSort(int A[],int n){
	
	for(int i=1;i<n-1;i++){
		int value=A[i];  
		int j=i;
		while(A[j-1]>A[j]){    //loop for shifting values greater than then [int value]
			A[j]=A[j-1];
			j--;
		}
		A[j]=value;            //arranging the array value
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
	
	InsertionSort(A,n);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
	

}
