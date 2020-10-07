//Time	complexity:	O(n)
//	Space	complexity: O(1)
#include<iostream>
using namespace std;
// Function For Linear Search
int LinearSearch(int A[],int n,int key){
	for(int i=0;i<n;i++){
		if(A[i]==key){
			return i;
		}
		
	}
	return -1;
}

int main(){
	int A[100];
	int n;
	int key;
	int i;
	cout<<"Enter the number of elements in array"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<"Enter the number to be searched"<<endl;
	cin>>key;
	i=LinearSearch(A,n,key);
	cout<<"The number is Found at the "<<i<<" location "<<endl;
	
	
	
}
