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
Node* BuildTree(int postorder[],int inorder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int idx=end;
    int curr=postorder[idx];
    idx--;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder,start,end,curr);  // 3. Search for idx in inorder
    node->right=BuildTree(postorder,inorder,pos+1,end);    // 4. from pos till end all will be right subtree
   node->left=BuildTree(postorder,inorder,start,pos-1); // 5. from start till pos all will be left subtree
   return node;
   
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
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    Node* root=BuildTree(postorder,inorder,0,4);
    InOrder(root);
}