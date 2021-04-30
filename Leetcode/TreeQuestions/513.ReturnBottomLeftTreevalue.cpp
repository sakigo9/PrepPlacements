#include<vector>
#include<queue>
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
/*
     Method 1 : Just return the last element of left View Tree
     Method 2:  Traverse the level Order than just return root->val at last


*/



class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return {};
    queue<TreeNode*> q;
        vector<int> v;
    q.push(root);
        while(!q.empty()){
        int n=q.size();
        
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(i==0){
                v.push_back(node->val);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
    }
        return v[v.size()-1];
    }
};

/*

method 2    

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root=q.front(); // get the value before pop coz pop will not return anyy val
            q.pop();
            if (root->right) {
                q.push(root->right);
            }
            if(root->left) q.push(root->left);
        }
        return root->val;
        
    }
};
*/