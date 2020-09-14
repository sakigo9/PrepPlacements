//--------******<<STACK>>******----------------

// Uses the **LIFO**-Last in First out [The one that comes late is the one that goes out]
// Also **FILO**-First in Last out-The one that comes First is the one that leaves the last.
//Application:
//				1. Balancing the symbols
//				2. Infix to Postfix/prefix conversion
//				3. Redo-Undo in the Editors
//				4.Forward and Backward Feature in the Browser
//              5. Cache Memory
#include<iostream>
#include<string>
using namespace std;

class Stack{
	private:
	int top;
	int arr[5];
	
	public:
		Stack(){
			top=-1;
			for(int i=0;i<5;i++){
				arr[i]=0;
			}
		}
		// Checking if the stack is Empty or not
		bool isEmpty(){
			if(top==-1)
			  return true;
			else
			  return false;
		}
		// Checking if the Stack is Full or not
		bool isFull(){
			if(top==5)
			  return true;
			else
			  return false;
		}
		// Push Operation
		void push(int val){
			if(isFull()){
				cout<<"Stack Overflow\n";
			}
			else{
				top++;
				arr[top]=val;
			}
		}
		// Pop Operation
		int pop(){
			if(isEmpty()){
				cout<<"Stack Underflow Cant pop anything\n";
			}
			else{
				int r = arr[top];
				arr[top]=0;
				top--;
				return r;
			}
			
		}
		// Count Operation
		int count(){
			return top+1;
		}
		//Peek Operation -Gives the value at the Index Position
		int peek(int pos){
			if(isEmpty()){
				cout<<"Empty Stack enter Valid Position\n";
			}
			else{
				return arr[pos];
			}
		}
		//Update the Stack Value
		void update(int val,int pos){
			arr[pos]=val;
			cout<<"Value "<<val<<" added at the position"<<pos<<endl;
		}
		//Printing
		void print(){
			for(int i=4;i>=0;i--){
				cout<<arr[i]<<endl;
			}
		}
	
};


int main(){
	Stack s1;
	int option,pos,val;
	do{
		cout<<"\n STACK OPERATIONS MENU ---> To Exit type 0"<<endl;
		cout<<" 1. PUSH"<<endl;
		cout<<" 2. POP"<<endl;
		cout<<" 3. DISPLAY"<<endl;
		cout<<" 4. UPDATE"<<endl;
		cout<<" 5. IS EMPTY"<<endl;
		cout<<" 6. IS FULL"<<endl;
		cout<<" 7. PEEK"<<endl;
		cout<<" 8. COUNT"<<endl;
		cout<<" 9. CLEAR"<<endl;
		cin>>option;
			switch(option){
			case 0: 
			break;
			case 1: 
			    cout<<"Enter the Value to PUSH\n";
			    cin>>val;
			    s1.push(val);
			break;
			case 2: 
			     cout<<"The data that popped :"<<s1.pop()<<endl;
			break;
			case 3: 
			     s1.print();
			break;
			case 4:
			     cout<<"Enter Value and Position for Updating data\n";
				 cin>>val;
				 cin>>pos;
				 s1.update(val,pos); 
			break;
			case 5:
			     if (s1.isEmpty())
				    cout<<" Stack is Empty\n"; 
				 else
				    cout<<" Stack has data\n";   
			break;
			case 6: 
			      if (s1.isFull())
				    cout<<" Stack is Full\n"; 
				 else
				    cout<<" Stack has Space left\n"; 
			break;
			case 7: 
			   cout<<"Enter the position whose value you want\n";
			   cin>>pos;
			   cout<<"Value at the postion is  :"<<s1.peek(pos)<<endl;
			break;
			case 8:
			    cout<<"Count is : "<<s1.count()<<endl; 
			break;
			case 9:
				system("cls");
				break;
			default:
				cout<<"Enter Valid Option number"<<endl;
		}
		
		
		
		
	}while(option!=0);
	
}

