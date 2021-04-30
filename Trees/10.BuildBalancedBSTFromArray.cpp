#include<iostream>
#include<vector>
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
void preOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
Node* BSTFromArray(vector<int> a,int start,int end){
    if(start>end) return NULL;
    int mid=(end+start)/2;
    Node* node=new Node(a[mid]);
    node->left=BSTFromArray(a,start,mid-1);
    node->right=BSTFromArray(a,mid+1,end);
    return node;
    
}

int main(){
    vector<int>a{1,2,3,4,5};
    Node* n=BSTFromArray(a,0,4);
    preOrder(n);
    
}