//Advantage : Used to implement stack and queue.
//            2.Implementing Graphs
//            3.Implementing Hash Tables
//            4.Undo Funtionality

#include<iostream>
using namespace std;

class Node{
	public:
		int key;
		int data;
		Node* next;
		
		Node(){
			key=0;
			data=0;
			next=NULL;
		}
	    Node(int k,int d){
	    	key=k;
	    	data=d;
		}
};

class SinglyLinkedList{
	public:
		Node* head;
		SinglyLinkedList(){
			head=NULL;
		}
		SinglyLinkedList(Node* n){
			head=n;
		}
		
		// Check if node exist using key value
		Node* nodeExist(int k){
			Node* temp=NULL;
				
			Node* ptr=head;
 			while(ptr!=NULL){
				if(ptr->key==k){
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
		}
		// Append Node---> Last
		void appendNode(Node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already exist\n";
			}
			else{
				if(head==NULL){
					head=n;
					cout<<"Appended"<<endl;
				}
				else{
					Node* str=head;
					while(str->next!=NULL){
						str=str->next;
					}
					str->next=n;
					cout<<"Added to Last"<<endl;
				}
			}
		}
		// Prepend Node----> At first
		void prependNode(Node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already exist\n";
			}
			else{
		
			if(head==NULL){
				head=n;
			}
			else{
			       n->next=head;  //new node should point to head address that is previous first node
			       head=n;  
			}
				}
		}
		// Insert after a particular Node
		void InsertBetween(int k,Node* n){
			Node* ptr=nodeExist(k);    //using nodeExist function we dont have to traverse again as it will directly gives the node with address
			if(ptr==NULL){
				cout<<"no Node with that key value"<<endl;
			}
 			else{
 				if(nodeExist(n->key)!=NULL){
				cout<<"Node already exist\n";
			}
			else{
				n->next=ptr->next;  // connecting new node address to next
				ptr->next=n;
				cout<<"Added "<<endl;
			}
 				
			 }
		}
		
		// Deleting a particular node
		void DeleteNode(int k){
			if(head==NULL){
				cout<<"Empty"<<endl;
			}
			else{
				if(head->key==k){
					head=head->next;
					cout<<"First node deleted"<<endl;
				}
				else{
					Node* temp=NULL;      //we will start with checking second node if that is to be deleted
					Node* preptr=head;    //A Node type before the node to be deleted
					Node* currentptr=head->next;  // A node after the node to be deleted
					while(currentptr!=NULL){
						if(currentptr->key==k){
							temp=currentptr;
							currentptr=NULL;
						}
						else{
							preptr=preptr->next;
							currentptr=currentptr->next;
						}
					}
					if(temp!=NULL){
						preptr->next=temp->next;
						cout<<"Node Deleted"<<endl;
					}else{
						cout<<"Node Doesnt Exist with that key"<<endl;
					}
				}
			}
		}
		
		// Update the Value in the node
		void updateByKey(int k,int d){
			Node* ptr=nodeExist(k);
			if (ptr==NULL){
				cout<<"Key Not present"<<endl;
			}
			else{
				ptr->data=d;
				cout<<"Data Updated"<<endl;
			}
		}
		//Printing the nodes
		void printList(){
			if(head==NULL){
				cout<<"Empty List"<<endl;
			}else{
				Node* ptr=head;
				while(ptr!=NULL){
					cout<<"The value is -----> ( "<<ptr->key<<" , "<<ptr->data<<" )"<<endl;
					ptr=ptr->next;
				}
			}
		}
};





int main(){
	
	SinglyLinkedList s;
	int option;
	int key1,k1,data1;
	do{
		cout<<"\n SINGLY LINKED LIST OPERATIONS MENU ---> To Exit type 0"<<endl;
		cout<<" 1. APPEND NODE"<<endl;
		cout<<" 2. PREPEND NODE"<<endl;
		cout<<" 3. INSERT NODE AFTER"<<endl;
		cout<<" 4. DELETE NODE BY KEY"<<endl;
		cout<<" 5. UPDATA DATA"<<endl;
		cout<<" 6. PRINT"<<endl;
		cout<<" 7. CLEAR SCREEN"<<endl;
		cin>>option;
		Node* n1= new Node();
		switch(option){
			case 0: 
			break;
			case 1:
				cout<<"Append node Operation : \nEnter Key and data value"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend node Operation : \nEnter Key and data value"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"Insert After Operation : \nEnter key of existing Node after which you want to add new Node"<<endl;
				cin>>k1;
				cout<<"Enter unique Key and data for new Node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.InsertBetween(k1,n1);
				break;
			case 4:
				cout<<"Delete Node Operation : \nEnter key of existing Node"<<endl;
				cin>>k1;
				s.DeleteNode(k1);
				break;
			case 5:
				cout<<"Update node Operation : \nEnter Key and data value to be Updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateByKey(key1,data1);
				break;
			case 6:
				s.printList();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter Valid Option number"<<endl;
		}
	}while(option!=0);
	
	
}
