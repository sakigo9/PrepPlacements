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
    void Level(TreeNode* root,vector<vector<int>>& v){
        
        if(root==nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
    
    while(!q.empty())
    {
        vector<int> temp;
        int n =q.size();

        for(int i = 1; i <= n; i++)
        {
             TreeNode* node= q.front();
             q.pop();
             temp.push_back(node-> val);
             
             if(node -> left)
                 q.push(node -> left);
             if(node -> right)
                 q.push(node-> right);
        }   
        v.push_back(temp);
    }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        Level(root,v);
        return v;
    }
};
