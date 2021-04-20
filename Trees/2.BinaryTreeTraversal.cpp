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
// 1. preOrder
void preOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// 2.InOrder
void InOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}

// 3.PostOrder
void PostOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}
int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preOrder(root);

    InOrder(root);

    PostOrder(root);
}