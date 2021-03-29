#include<iostream>
using namespace std;
int binarySearch(int arr[],int low,int high,int toFind){
    int mid = (low+high)/2;
    if(toFind==arr[mid])
        return mid;
    else if(toFind>arr[mid])
        return binarySearch(arr,mid+1,high,toFind);
    else if(toFind<arr[mid])
        return binarySearch(arr,low,mid-1,toFind);
}
int main(){
    int arr[] = {2,4,6,8,10,11};
    int toFind = 11;
    int low=0,high=5;
    cout<<"Found element "<<toFind<<" at index : "<<binarySearch(arr,low,high,toFind)<<endl;
    return 0;
}
