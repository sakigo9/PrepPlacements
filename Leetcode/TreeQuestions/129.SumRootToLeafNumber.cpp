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


                // time Complexity : O(n)

    int res=0;
    void dfs(TreeNode* root,int x){
        if(root==NULL) return;
        x*=10;
        x+=root->val;
        if(root->left==NULL && root->right==NULL){
            res+=x;
        }
        dfs(root->left,x);
        dfs(root->right,x);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root,0);
        return res;
    }
};