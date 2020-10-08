#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head = NULL;
    }
    void ShowLinkedList(){
        Node *temp=head;
        cout<<"===================================="<<endl;
        if(temp!=NULL)
            cout<<"Linked List : => ";
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL)
                cout<<"->";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"===================================="<<endl;
    }
    void addNode(){
        int data;
        cout<<"Enter data for new Node -> ";
        cin>>data;
        if(head==NULL){
            head = new Node();
            head->data = data;
            head->next = NULL;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
        }
        ShowLinkedList();
    }
    void addNodeParticular(){
        int data,position;
        cout<<"Enter data for new Node -> ";
        cin>>data;
        cout<<"Enter position for new Node -> ";
        cin>>position;
        Node *temp = head;
        Node *prev = NULL;
        int i=0;
        while(i<position-1){
            prev=temp;
            temp=temp->next;
            ++i;
        }
        if(temp==head){
            Node *newNode = new Node();
            newNode->data = data;
        	newNode->next = temp;
        	head = newNode;
        }
        else{
        	Node *newNode = new Node();
        	newNode->data = data;
        	newNode->next = temp;
        	prev->next = newNode;
		}
        ShowLinkedList();
    }
    void deleteNode(){
        Node *temp = head;
        cout<<"Enter which node you want to delete : ";
        int targetIndex;
        cin>>targetIndex;
        Node *prev = NULL;
        int i=0;
        while(i<targetIndex-1){
            prev=temp;
            temp=temp->next;
            ++i;
        }
        cout<<"Deleting "<<temp->data<<endl;
        if(temp==head){
            head=temp->next;
        }
        else{
            prev->next=temp->next;
        }
    }
    
};
int main(){
    LinkedList list = LinkedList();
    while(true){
	    int choice;
    	cout<<"1. Add Node to the LinkedList"<<endl;
    	cout<<"2. Add Node to the LinkedList at a particular position"<<endl;
    	cout<<"3. Delete a Node from the LinkedList"<<endl;
    	cout<<"4. Show Nodes of the LinkedList"<<endl;
        cout<<"5. EXIT"<<endl;
    	cout<<"CHOICE=> ";
    	cin>>choice;
    	switch(choice){
    		case 1:
                list.addNode();
                break;
            case 2:
                list.addNodeParticular();
                break;
            case 3:
                list.deleteNode();
    			break;
            case 4:
                list.ShowLinkedList();
                break;
            case 5:
                exit(420);
		}
	}
    return 0;
}
