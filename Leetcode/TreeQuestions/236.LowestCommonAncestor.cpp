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

        // Method 1

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr or root == p or root == q )
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor( root->left, p, q );
        TreeNode* right = lowestCommonAncestor( root->right, p, q );
        
        if( left == nullptr )
        {
            return right;
        }
        
        if( right == nullptr )
        {
            return left;
        }
        
        return root;
    }

    /*
    
        Method 2


        class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        
        TreeNode* left_node=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_node=lowestCommonAncestor(root->right,p,q);
        
        if(left_node!=NULL && right_node!=NULL) return root;
        if(left_node==NULL && right_node==NULL) return NULL;
        
        if(left_node!=NULL) return left_node;
        return right_node;
    }
};

    */