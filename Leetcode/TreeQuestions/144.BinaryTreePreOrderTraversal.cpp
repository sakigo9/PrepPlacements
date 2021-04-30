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
    void PreOrder(TreeNode* node, vector<int>& v){
        if (node == nullptr)
            return;
        v.push_back(node->val);
        PreOrder(node->left,v);
        PreOrder(node->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        PreOrder(root,v);
        return v;        
    }
};
