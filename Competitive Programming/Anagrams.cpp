#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram (string A, string B){
 int n1, n2, i;
 n1 = A.length();
 n2 = B.length();
 if(n1 != n2)
  return false;
 sort(A.begin(), A.end());
 sort(B.begin(), B.end());

 for(i =0 ; i<n1 ; i++)
 {
  if( A[i] != B[i] )
  return false;
 }
return true;
}

int main()
{
 string A,B;
 bool ans;
 cout<<"Enter first word\n";
 cin>>A;
 cout<<"Enter second word\n";
 cin>>B;
 ans = isAnagram(A,B);
 if(ans==1)
 cout<<"Words are anagrams\n";
 else
 cout<<"Words are not anagrams";
 return 0;
}
