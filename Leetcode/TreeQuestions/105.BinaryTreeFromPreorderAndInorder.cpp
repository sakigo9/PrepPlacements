
#include<vector>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };class Solution {
public:
    
    int find(vector<int>& preorder, vector<int>& inorder,int n,int k){
        for(int i=0;i<n;i++){
            if(k==inorder[i]) return i;
        }
        return -1;
    }
    
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,int n,int start, int end, int &curr){
        if(start>end) return NULL;
        TreeNode* newnode= new TreeNode(preorder[curr]);
        int mid=find(preorder,inorder,n,preorder[curr]);
        curr++;
        newnode->left=tree(preorder,inorder,n,start,mid-1,curr);
        newnode->right=tree(preorder,inorder,n,mid+1,end,curr);   
        return newnode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int start=0, end=n-1, curr=0;
        TreeNode *root=tree(preorder,inorder,n,start,end,curr);
        return root;
    }
};