//  STATIC VARIABLES AND FUNCTIONS
//  1.Static variable is common to all the objects
//  2.Retains its value throughout the program.
//  3.Static Variables are initialized outside the member function or class Defination
#include<bits/stdc++.h>
using namespace std;

class Sample{
	private:
		int a;
	public:
		static int b;
		static void value(){
			cout<<"Static Value : "<<b;
		}
};
int Sample::b=9;  //defined outside the class

int main(){
//	Sample s;
//	s.b=0;
//	cout<<s.b<<endl;
	Sample::value();  //Called without an object
}
