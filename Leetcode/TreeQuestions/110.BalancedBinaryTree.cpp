
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
/*
     INTUITION:
     For Each and every Node calculate the difference of left subtree height and right subtree height.

*/
    int Height(TreeNode* root){
        if(root==NULL) return 0;
        int L=Height(root->left);
        int R=Height(root->right);
        return max(L,R)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lpart=Height(root->left);
        int rpart=Height(root->right);
        if(abs(lpart-rpart)<2 && isBalanced(root->left)&&isBalanced(root->right)){
            return true;
        }
        else{
            return false;
        }
    }



/*
   OPTIMAL SOLUTION : Do same thing as that of finding the height of BST with some additional check statement
   METHOD 2 : Space Complexity: O(N), Time Complexity: O(N)

*/

     int height(TreeNode* root, bool& isBal)
    {
        if(isBal == false) //don't check further nodes
            return 0;
        
        if(root == NULL)
            return 0;

        int lh = height(root->left, isBal);
        int rh = height(root->right, isBal);

        if(abs(lh - rh) > 1) //condition violated
            isBal = false;

        return max(lh, rh)+1;

    }
    
    bool isBalanced(TreeNode* root) 
    {
        bool isBal = true;
        int ht = height(root, isBal);
        return isBal;
    }
};

