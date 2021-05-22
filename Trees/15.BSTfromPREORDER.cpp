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

/*

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        TreeNode* root=NULL;
        for(int i: preorder){
            root=helper(root,i);
        }
        return root;
    }
    TreeNode* helper(TreeNode* root,int curr){
        if(!root) return new TreeNode(curr);
        if(curr<root->val) root->left=helper(root->left,curr);
        else root->right=helper(root->right,curr);
        return root;
    }
};


*/
Node* BST(vector<int>& v){
   
}
void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}
int main(){
    vector<int> preorder{7,5,4,6,8,9};
    Node* root=BST(preorder);
    InOrder(root);
}