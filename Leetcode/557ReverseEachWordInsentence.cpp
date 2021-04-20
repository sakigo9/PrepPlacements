
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string reverse2(string s){
    for(int i=0;i<s.size()/2;i++){
        swap(s[i],s[s.size()-i-1]);
    }
    return s;
}
string reverseWord(vector<string> v){
    string ans;
    for(auto i:v){
        ans+=reverse2(i);
        ans+=' ';
    }
    return ans.substr(0,ans.size()-1);
}
int main()
{
  string s="let's party today";
  
  int n=s.size();
  string word;
  vector<string> v ;
  for(auto i:s){
      if(i==' '){
          v.push_back(word);
          word="";
      }
      else{
          word+=i;
      }
  }
  v.push_back(word);
  for(auto i: v){
      cout<<i<<" "<<endl;
  }
  cout<<reverseWord(v);
}
