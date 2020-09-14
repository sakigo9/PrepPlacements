



#include<iostream>
using namespace std;

class Node{
	public:
		int key;
		int data;
		Node* next;
		Node* previous;
		
		Node(){
			key=0;
			data=0;
			next=NULL;
			previous=NULL;
		}
	    Node(int k,int d){
	    	key=k;
	    	data=d;
		}
};
class DoublyLinkedList{
	public:
		Node* head;
		DoublyLinkedList(){
			head=NULL;
		}
		DoublyLinkedList(Node* n){
			head=n;
		}
		
		// Checking the Key values if that exists or not
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
		
		// Append the Node
		void appendNode(Node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already exist\n";
			}
			else{
				if(head==NULL){
					head=n;
					cout<<"Appended"<<endl;
				}else{
						Node* str=head;
					while(str->next!=NULL){    // str-> next used in place of just str because we already handled first case
						str=str->next;
					}
					str->next=n;
					n->previous=str;
					cout<<"Added to Last"<<endl;
				}
		}
	}
	      // Prepend  the Node
	      void prependNode(Node* n){
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already exist\n";
			}
			else{
		
			if(head==NULL){
				head=n;
			}
			else{
			      head->previous=n;
			       n->next=head;
			       head=n;
			       cout<<"Node Prepended"<<endl;
			}
				}
		}
	      
	       
			// Inserting Node in between
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
				Node* nextnode=ptr->next;
				if(nextnode==NULL){
					ptr->next=n;
					n->previous=ptr;
					cout<<"Inserted at end\n";
				}else{
					   n->next= ptr->next;
				n->next->previous=n;
				n->previous=n;
				ptr->next=n;
				}
				
				
				
				
			}
 				
			 }
		}
		// Deleting  a  Node
		void DeleteNode(int k){
			Node* ptr=nodeExist(k);
			if(ptr==NULL){
				cout<<"Node doesn't Exist\n";
			}
			else{
				
				if(head->key==k){
					head=head->next;
				
				}
				else {
					Node* nextNode=ptr->next;
					Node* prevNode=ptr->previous;
					if(nextNode==NULL)         // pyt->next because we already checked for the head condition
					{
						prevNode->next=NULL;
						cout<<"Node deleted at end\n";
					}else{
						prevNode->next=nextNode;
						nextNode->previous=prevNode;
						cout<<"Node at Between Deleted\n";
					}
				}
			}
		}
		
		// Update Node data
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

			
	DoublyLinkedList s;
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
