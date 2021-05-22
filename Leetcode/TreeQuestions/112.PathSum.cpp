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
  };
class Solution {
public:
    bool hasPathSum(TreeNode* root, int t) {
        if(root==NULL) return false;
        int sum;
        sum=t-root->val;
        if(sum==0 && root->left==NULL && root->right==NULL) return true;
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
    }
};