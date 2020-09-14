# include<iostream>
# include<string.h>
using namespace std;
class queue
{
	private:
		int front;
		int rear;
		int arr[5];
	public:
		queue()
		{
			front=-1;
			rear=-1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
	bool isempty()
	{
		if(front==-1 && rear==-1)
		    return true;
		else
		    return false;
	}
	bool isfull()
	{
		if(rear==5-1)
		 return true;
		else
		  return false;
	}
	int enqueue(int val)
	{
		if(isfull())
		{
			cout<<"queue is FULL"<<endl;
		return 0;
		}	 
		else if(isempty())
		{
			front=rear=0;
			arr[rear]=val;
		}
		else
		{
			rear++;
			arr[rear]=val;
			
		}
		
	}
	int dequeue()
	{
		int x;
		if(isempty())
		{
			cout<<"queue is empty"<<endl;
			return 0;
		}
		else if(front==rear)
		{
			x=arr[front];
			arr[front]=0;
			front=-1;
			rear=-1;
		}
		else
		{
			x=arr[front];
			arr[front]=0;
			front++;
		
		
		}	return x;
		
		
	}
	int count()
	{
		return(rear-front+1);
	}
	void display()
	{
		for(int i=0;i<5;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
		
};
int main()
{
	queue q1;
	int option ,value;
	do{
		cout<<"select the function you want to perform,enter 0 to exit"<<endl;
 		cout<<"1 enqueue()"<<endl;
 		cout<<"2 dequeue()"<<endl;
 		cout<<"3 isempty()"<<endl;
 		cout<<"4 isfull()"<<endl;
 		cout<<"5 count()"<<endl;
 		cout<<"6 display()"<<endl;
 		cout<<"7 clear screen"<<endl;
 		cin>>option;
 		switch(option)
 		{
 			case 1:
 				cout<<"enter an item to enqueue in the queue"<<endl;
 				cin>>value;
 				q1.enqueue(value);
 				break;
 			case 2:
 				cout<<"dequeue function called "<<q1.dequeue()<<endl;
 				
 				break;
 			case 3:
 				if(q1.isempty())
 				{
 					cout<<"queue is empty"<<endl;
				 }
				 else
				 {
				 		cout<<"queue is not empty"<<endl;
				 }
				 break;
			case 4:
				if(q1.isfull())
				
				{
						cout<<"queue is full"<<endl;
				}
				else
				{
						cout<<"queue is not full"<<endl;
				}
				break;
		    case 5:
				cout<<"count of the queue is"<<q1.count()<<endl;
                		
				break;	
			case 6:
			      cout<<"the queue elements are"<<endl;
				q1.display();
			   break;
			case 7:
				system("cls");
				break;
		    default:
		     cout<<"enter the proper option"<<endl;
	}
	}
	while(option!=0);
	return 0;
}
