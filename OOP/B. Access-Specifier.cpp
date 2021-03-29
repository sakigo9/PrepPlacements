// 1.Abstraction : Denotes the essential characteritics of an object that distinquishes it from all the other kinds of objects.
// 2. Encapsulation is the process of hiding all of the details of an object that do not continue to its essential characteristics.
// 3. Access Specifier : Public Protected Private
// 3.1  the public access specifier allow a class to expose its member variables and member function to other functions and objects.
// 3.3  The Private allows DATA HIDING as it hides the member functions and member variables to other class objects and functions.
// 3.2 Protected is same.



#include<iostream>
using namespace std;

class Car{//Cfeating class car
	
	private://acess specifier private
		char model[12];
		void brand(){
			cout<<"function brand";
		}
	public://acess specifier public
		char color[21];
		void speed(){
			cout<<"function speed";
		}
	          void cost(int a){
		   cout<<" Spped function : " a<<endl;
		  }
	protected:
		char location[23];
		void price(){
			cout<<"function price";
		}

};


int main(){
	Car ford;
	ford.speed();
	Car swift;
	swift.cost(7000000);  // parameterized call
	// ford.brand();             error
	//cout<< ford.location;      error
	// ford.price();             error
}
