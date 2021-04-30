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
    // we know left subtree values will be less than root and right subtree is greater than root
    // Runtime : 16ms
    bool isBST(TreeNode* root,TreeNode* min=NULL,TreeNode* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && min->val>=root->val) return false;
    if(max!=NULL && max->val<=root->val) return false;
    int Lvalid=isBST(root->left,min,root);
    int Rvalid=isBST(root->right,root,max);
    return Lvalid && Rvalid;
    
}
    bool isValidBST(TreeNode* root) {
       if(isBST(root,NULL,NULL)){
        return true;
    }else{
        return false;
    }
    }
};

// Method 2: BEST METHOD [ we know the inorder of a BST is always sorted]
// Runtime 8ms


/*
class Solution {
public:
    vector<int> order;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        inOrder(root);
        for (size_t i = 0; i < order.size() - 1; i++) {
            if (order[i] >= order[i + 1]) return false;
        }
        return true;
    }
    
    void inOrder(TreeNode* root) {
        if (!root) return ;
        inOrder(root->left);
        this->order.push_back(root->val);
        inOrder(root->right);
    }
};


// Same as Method 2 using vector
// Runtime : 16ms

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> vec;
        return inorder(root,vec);    
    }
private:
    bool inorder(TreeNode*root,vector<int> &vec)
    {
        if(root==NULL)
            return true;
        bool left=inorder(root->left,vec);
        if(vec.size()==0)
            vec.push_back(root->val);
        else if(vec[vec.size()-1]>=root->val)
            return false;
        else
            vec.push_back(root->val);
        bool right=inorder(root->right,vec);
        return left&&right;
    }
};


*/