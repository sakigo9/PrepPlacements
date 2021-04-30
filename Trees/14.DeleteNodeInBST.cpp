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
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* DeleteBST(Node* root, int key){
    if(root==NULL) return NULL;
    else if(key>root->val) return DeleteBST(root->right,key);
    else if(root->val>key) return DeleteBST(root->left,key);
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root); 
            return temp;
        }
        else if(root->right==NULL){
           Node* temp=root->left;
            free(root);
            return temp;
        }else{
        Node* temp=inorderSucc(root->right);
        root->val=temp->val;
        root->right=DeleteBST(root->right,temp->val);
        }
    }
return root;

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
    struct Node* root= new Node(9);
    root->left=new Node(6);
    root->right=new Node(11);
    root->left->left=new Node(3);
    root->left->right=new Node(7);
    root->right->left=new Node(10);
    root->right->right=new Node(71);
    InOrder(root);
    cout<<endl;
    root=DeleteBST(root,6);
    InOrder(root);
}