#include<bits/stdc++.h>
using namespace std;
class B;
class A{//class created named A
	private://acess specifier
		int x;
	public:
		void setdata(int i){
			x=i;
		}
	friend void min(A,B);
};
class B{
	private:
		int y;
	public:
		void setdata(int i){
			y=i;
		}
	friend void min(A,B);
};
void min(A a,B b){
	if(a.x<b.y){
		cout<<a.x;
	}
	else{
		cout<<b.y;
	}
}
int main(){
	A a;
	B b;
	a.setdata(12);
	b.setdata(13);
	min(a,b);
}
