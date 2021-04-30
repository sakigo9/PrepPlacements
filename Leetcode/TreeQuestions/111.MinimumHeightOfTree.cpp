// Three Solutions
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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0 || r==0){
        return max(l,r)+1; // max is returned when it is either left skewed tree or right skewed tree
        }
        return min(l,r)+1;
    }
      

};
/*

METHOD 2 : BFS---->using Queue

class Solution {
public:
    int minDepth(TreeNode* root) {
        int minimumDepth = 1;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            for(int i=0,n=q.size();i<n;i++){
                TreeNode* p = q.front();
                q.pop();
                if(p->left==NULL && p->right==NULL) return minimumDepth;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            minimumDepth++;
        }
        return minimumDepth;
    }
};



*/

/*

METHOD 3 : DFS

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
*/
