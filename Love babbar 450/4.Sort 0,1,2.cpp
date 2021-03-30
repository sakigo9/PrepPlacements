// Dutch Natinal Flag Problem
#include <iostream>

using namespace std;
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int main()
{
    int A[]={1,2,1,1,2,0,0,1,0,1,2,0,1};
    int n=sizeof(A)/sizeof(A[0]);
    int end=n-1;
    int start = 0, mid = 0;
    int pivot = 1;
 
    while (mid <= end)
    {
        if (A[mid] < pivot)         
        {
            swap(A, start, mid);
            ++start, ++mid;
        }
        else if (A[mid] > pivot)    
        {
            swap(A, mid, end);
            --end;
        }
        else {                      
            ++mid;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    
}
