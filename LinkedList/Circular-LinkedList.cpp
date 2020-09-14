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

class CircularLinkedList{
	public:
		Node*head;
		CircularLinkedList(){
			head=NULL;
		}
		CircularLinkedList(Node* n){
			head=n;
		}
		//Check if node exist or not
		Node* nodeExist(int k){
			Node* temp=NULL;
			Node* ptr=head;
			if(ptr==NULL){
				return temp;
				
			}  						// do while loop compulsary
			do{                   // if just while loop is used then ptr!=head never gets exected as we assign ptr=head at starting
			
				if(ptr->key==k){ 
					temp=ptr;
				}
				ptr=ptr->next;
			}while(ptr!=head);    // Circular so last will point to first Node so we used !=head
			return temp;
		}
		//Appending Node 
		void appendNode(Node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already Exist with the key :"<<n->next<<endl;
			}
			else{
				if(head==NULL){
					head=n;
					n->next=head;   //Because its a Circular Node
					cout<<"Appended the First at the Head\n";
				}
				else{
					Node* ptr=head;
					while(ptr->next!=head){   //ptr->next in place of just ptr beacuse we handle first node case while this one refers 2nd Node 
						ptr=ptr->next;
					}
					ptr->next=n;
					n->next=head;
					cout<<"Appended at Last\n";
				}
			}
		}
		// Prepend Node
		void prependNode(Node *n){
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already Exist with the key :"<<n->next<<endl;
			}
			else{
				if(head==NULL){
					head=n;
					n->next=head;
					cout<<"First Node Added\n";
				}
				else{
					Node* ptr=head;
					while(ptr->next!=head){
						ptr=ptr->next;
					}
					ptr->next=n;    //using the same logic as append
					n->next=head;
					head=n;         //additional thing that refers n as head
					cout<<"Prepended Node\n";
				}
			}
		}
		// Between
		void InsertBetween(int k,Node* n){
			Node* ptr = nodeExist(k);
			if (ptr==NULL){
				cout<<"Node with the key "<<k<<" Doesnt exist\n";
			}else{
				if(nodeExist(n->key)!=NULL){
						cout<<"Node already Exist with the key :"<<n->next<<endl;
				}else{
					if(ptr->next==head){       //checking if the key is of the last node after which new node id to be added
						ptr->next=n;
						n->next=head;
						cout<<"Inserted at the end\n";
					}
					else{
						n->next=ptr->next;   //after checking all condition ptr->next have the location after which we have to insert
						ptr->next=n;
						cout<<"Inserted at between\n";
					}
				}
			}
		}
		// Deleting
		
		void DeleteNode(int k){
			Node* ptr=nodeExist(k);
			if(ptr==NULL){
				cout<<"Node doesn't Exist\n";
			}
			else{
				if(ptr==head){   //When we want to delete head Node itself 1. when we want to delete the only node 2. when we want to delete first node of many nodes available
				        
					if(head->next==NULL)  {// head->next is node after the head also when there is only one Node
						head=NULL;
						cout<<"Head Node unlinked\n";
					}else{    // when we have more than one Node but want to delete the first node in that
						Node* ptr1=head;
						while(ptr1->next!=head){
							ptr1=ptr1->next;
						}
						ptr1->next=head->next;
						head=head->next;
						cout<<"Unlinked First Node \n";
					}
	   			}
						else{
								Node* temp=NULL;
								Node* prevptr=head;
								Node* currentptr=head->next;
								while(currentptr!=NULL){
									if(currentptr->key==k){
										temp=currentptr;
										currentptr=NULL;
									}
									else{
										prevptr=prevptr->next;
										currentptr=currentptr->next;
									}
								}
								prevptr->next=temp->next;
								cout<<"Node Unlinked present at the middle\n";
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
				do{
					cout<<"The value is -----> ( "<<ptr->key<<" , "<<ptr->data<<" )"<<endl;
					ptr=ptr->next;
				}while(ptr!=head);
			}
		}
		
};







int main(){
	
	CircularLinkedList s;
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
