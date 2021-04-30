#include<vector>
#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    void Inorder(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        Inorder(root,v);
        int n = v.size();
    if(k > n){
         return -1;
    }else{
         return v[k -1];
    }
       
   
        
    }
};