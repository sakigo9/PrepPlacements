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
private:
    int rob(TreeNode* root, int &notRobMax) {
        if (!root) return 0;
        int  leftNotRobMax = 0, rightNotRobMax = 0;
        int leftMax = rob(root->left, leftNotRobMax);
        int rightMax = rob(root->right,rightNotRobMax);
        notRobMax = leftMax + rightMax;
        return max(root->val + leftNotRobMax + rightNotRobMax, notRobMax);
    }
public:
    int rob(TreeNode* root) {
        int notRobMax = 0;
        return rob(root , notRobMax);
    }
};

                    // Top Down DP





// class Solution {
// public:
//     map<TreeNode*,int> dp;
//     int dfs(TreeNode* root){
//         if(!root) return 0;
//         if(dp.find(root) != dp.end()) return dp[root];
//         int ma = dfs(root->left)+dfs(root->right), ls = 0, rs = 0;
//         if(root->left)
//             ls = dfs(root->left->left)+dfs(root->left->right);
//         if(root->right)
//             rs = dfs(root->right->left)+dfs(root->right->right);
//         ma = max(ma,root->val+ls+rs);
//         return dp[root] = ma;
//     }
//     int rob(TreeNode* root) {
//         return dfs(root);
//     }
// };