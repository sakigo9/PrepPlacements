// Role of <return 0;>  --> Tells the OS that code doesnt have any error
// The compiler convert Code into Object code
// Array always end with a NULL(\0)
// An array can not be initialized with another array



#include<iostream>
using namespace std;


class Basics{
	float a;
	int b;
	public:
		void display(){
			cout<<"\n value of variables"<<a;
			cout<<" \n value of  second variables"<<b;
		}
		void accept(){
			cout<<"\nEnter the value of a";
			cin>>a;
			cout<<"\nEnter the value of b";
			cin>>b;
		}
};


int main(){
	 Basics obj[2];   //Declares an array of user-defined data type
	 obj[0].accept();
	 obj[1].accept();
	 obj[0].display();
	 obj[1].display();
}
