#include<vector>
#include<iostream>
#include<algorithm>
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
    
    TreeNode* Fun(TreeNode* root,int val){
        if(root==NULL) return NULL;
        if(root->val==val) {
            return root;
        }
        if(root->val<val) return Fun(root->right,val);
        return Fun(root->left,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        vector<int> v;
        TreeNode* node=Fun(root,val);
        
        return node;
    }
};