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
    void PostOrder(TreeNode* node, vector<int>& v){
        if (node == nullptr)
            return;
        
        PostOrder(node->left,v);
        PostOrder(node->right,v);
        v.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        PostOrder(root,v);
        return v;
    }
};
