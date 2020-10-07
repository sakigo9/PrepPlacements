#include <iostream> 
#include <algorithm> 
  
using namespace std; 
  
void show(int a[]) 
{ 
    for(int i = 0; i < 10; ++i) 
        cout << a[i] << " "; 
} 
  
int main() 
{  
    int n;
  cin>>n;
  int a[n];
  for(int i = 0; i < n; ++i) cin>>a[i];
    //int a[10]= {1, 5, 8, 9, 6, 7, 3, 4, 2, 0}; 
    cout << "\n The array before sorting is : "; 
    show(a); 
  
    sort(a, a+10); 
  
    cout << "\n\n The array after sorting is : "; 
    show(a); 
  
    return 0; 
  
} 
