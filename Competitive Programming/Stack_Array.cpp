#include<iostream>
using namespace std;
class Stack{
    public:
    int top_;
    int size;
    int arr[10];
    Stack(){
        size=10;
        top_=-1;
    }
    void push(int x){
        top_ = top_+1;
        if(top_>=size){
            cout<<"Stack Overflow!"<<endl;
            top_ = top_-1;
            return ;
        }
        arr[top_] = x;
    }
    bool isEmpty(){
        if(top_==-1)
            return true;
        return false;
    }
    bool pop(){
        if(top_==-1)
            return false;
        top_ = top_-1;
        return true;
    }
    int top(){
        return arr[top_];
    }
    void showStack(){
        cout<<"===================================="<<endl;
        int starting = top_;
        // cout<<"Starting -> "<<starting<<endl;
        while(starting>=0){
            cout<<arr[starting]<<endl;
            starting = starting-1;
       		// cout<<"Starting -> "<<starting<<endl;
        }
        cout<<"===================================="<<endl;
    }
};
int main(){
    Stack stack;
    while(true){
        int choice;
        cout<<"1. Push element to Stack [push()]"<<endl;
        cout<<"2. Pop element from Stack [pop()]"<<endl;
        cout<<"3. Top element of Stack [top()]"<<endl;
        cout<<"4. Stack empty or not [isEmpty() -> 0:false , 1:true]"<<endl;
        cout<<"5. Display stack"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"CHOICE ==> ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int x;
            cout<<"Enter element to push into the stack -> ";
            cin>>x;
            stack.push(x);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout<<"Top -> "<<stack.top()<<endl;
            break;
        case 4:
            cout<<"isEmpty : "<<stack.isEmpty()<<endl;
            break;
        case 5:
            stack.showStack();
            break;
        case 6:
            exit(5);
        }
    }
    return 0;
}
