#include<iostream>

using namespace std;
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

bool isBST(Node* root,Node* min=NULL,Node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && min->val>=root->val) return false;
    if(max!=NULL && max->val<=root->val) return false;
    int Lvalid=isBST(root->left,min,root);
    int Rvalid=isBST(root->right,root,max);
    return Lvalid && Rvalid;
    
}

int main(){
    struct Node* root= new Node(11);
    root->left=new Node(2);
    root->right=new Node(31);
    
    if(isBST(root,NULL,NULL)){
        cout<<"valid";
    }else{
        cout<<"Invalid";
    }
}