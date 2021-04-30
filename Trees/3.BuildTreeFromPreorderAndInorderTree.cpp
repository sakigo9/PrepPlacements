#include<iostream>
using namespace std;


struct Node{
      int data;
      struct Node* left;
      struct Node* right;

      Node(int val){
          data=val;
          left=NULL;
          right=NULL;
      }
};
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
    if(inorder[i]==curr){
        return i;
    }
    }
    return -1;
}
Node* buildTree(int preorder[],int inorder[],int start,int end ){
   if(start>end){
       return NULL;
   }
   static int idx=0;
   int curr=preorder[idx];    // 1. First take preorder first element
   idx++;
   Node* node=new Node(curr); // 2.we know that preorder first will be root of tree so build a node 
   if(start==end){
       return node;
   }
   int pos=search(inorder,start,end,curr);  // 3. Search for idx in inorder
   node->left=buildTree(preorder,inorder,start,pos-1); // 4. from start till pos all will be left subtree
   node->right=buildTree(preorder,inorder,pos+1,end);    // 5. from pos till end all will be right subtree
   


}

void InOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node* root= buildTree(preorder,inorder,0,4);
    InOrder(root);
}