#include<vector>
#include<iostream>
#include<queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          if(root==NULL){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> p;
            
            int n=q.size();
            
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                p.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(p);
        }
        for(int i=0;i<res.size();i++){
            if(i%2!=0){
                reverse(begin(res[i]),end(res[i]));
            }
        }
        return res;
    }
};