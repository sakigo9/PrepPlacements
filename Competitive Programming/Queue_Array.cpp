#include<iostream>
using namespace std;
class Queue{
    public:
    int arr[10],size;
    int front,rear;
    Queue(){
        size=10;
        front=-1;
        rear=-1;
    }
    void enQueue(int x){
        if(front==-1){
            front = front+1;
            rear = front;
            arr[front] = x;
            return ;
        }
        rear = rear+1;
        if(rear>=size){
            cout<<"Queue Overflow!"<<endl;
            rear = rear-1;
            return ;
        }
        arr[rear] = x;
    }
    void deQueue(){
        if(rear==-1){
            cout<<"Queue empty!"<<endl;
            return ;
        }
        cout<<"Dequeuing "<<arr[front]<<" from the Queue"<<endl;
        front = front+1;
        if(rear<front){
            front=-1;
            rear=-1;
        }
    }
    int front_(){
        if(front!=-1)
            return arr[front];
        return -1;
    }
    bool isEmpty(){
        if(rear==-1)
            return true;
        return false;
    }
    void showQueue(){
        int index = front;
        if(index==-1){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"===================================="<<endl;
        while(index<=rear){
            cout<<arr[index]<<" ";
            index=index+1;
        }
        cout<<endl<<"===================================="<<endl;
    }
};
int main(){
    Queue queue;
    int choice;
    while(true){
        cout<<"1. Enqueue the Queue"<<endl;
        cout<<"2. Dequeue the Queue"<<endl;
        cout<<"3. Front of the Queue"<<endl;
        cout<<"4. Queue , empty or not"<<endl;
        cout<<"5. Show Queue\n";
        cout<<"6. EXIT\n";
        cout<<"CHOICE => ";
        cin>>choice;
        switch(choice){
            case 1:
                int x;
                cout<<"Enter the element to enqueue into the Queue -> ";
                cin>>x;
                queue.enQueue(x);
                break;
            case 2:
                queue.deQueue();
                break;
            case 3:
                {
                    int front = queue.front_();
                    if(front==-1)
                        cout<<"Queue is Empty!"<<endl;
                    else
                        cout<<"Front in the Queue is "<<front<<endl;
                }
                break;
            case 4:
                cout<<"isEmpty() [0:false,1:true]: -> "<<queue.isEmpty()<<endl;
                break;
            case 5:
                queue.showQueue();
                break;
            case 6:
                exit(5);
        }
    }
    return 0;
}
