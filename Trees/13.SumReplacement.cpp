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
void SumReplacement(Node* root){
   if(root==NULL){
        return;
    }
    SumReplacement(root->left);
    SumReplacement(root->right);
    if(root->left!=NULL){
        root->val+=root->left->val;
    }
    if(root->right!=NULL){
        root->val+=root->right->val;
    }

}
void InOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}
int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    InOrder(root);
    cout<<endl;
    SumReplacement(root);
    InOrder(root);
}