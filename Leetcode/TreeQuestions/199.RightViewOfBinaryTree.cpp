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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
    queue<TreeNode*> q;
        vector<int> v;
    q.push(root);
        while(!q.empty()){
        int n=q.size();
        
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(i==n-1){
                v.push_back(node->val);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
    }
        return v;
    }
};

//Recusive Method : Go to each level and print when we come down to last element in each level

/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector <int> ans;
        int maxLevel = 0;
        helperVectorFunction(root,1,ans,maxLevel);
        return ans;
    }
    void helperVectorFunction(TreeNode* root,int rootLevel, vector<int> &ans, int &maxLevel){
        if(root == NULL){
            return ;
        }
        if(rootLevel > maxLevel){
            ans.push_back(root->val);
            maxLevel = rootLevel;
        }
        helperVectorFunction(root->right,rootLevel+1,ans,maxLevel);
        helperVectorFunction(root->left, rootLevel+1,ans,maxLevel);
    }
};

*/