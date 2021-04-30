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
//----------------------------------------------------------------------------
      // Optimal Solution : O(n)
     
	int depth(TreeNode* root,int& res){   //res enables to cal diameter within O(n)
		if(!root) return 0;
		int l=depth(root->left,res);
		int r=depth(root->right,res);
		res=max(res,l+r);  // Similar to currDia when root is included in diameter
		return max(l,r)+1; // Gives height of the left and right subtree
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int res=0;
		depth(root,res);
		return res;  
	}

//----------------------------------------------------------------------------


// Time Complexity : O(n*n)
    int height(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        /*
        Three Cases:
        case 1: Diameter consisting current node
        case 2: Left substree gives the max diameter
        case 3: Right substree gives the max diameter
        take max of case2 and case 3
        */

       // Case 1:
        int left_height=height(root->left);
        int right_height=height(root->right);
        int currdia=left_height+right_height;
        // Case 2:
        int L=diameterOfBinaryTree(root->left);
        // Case 3:
        int R=diameterOfBinaryTree(root->right);
        return max(currdia,max(L,R));
    }
};

// class Solution {
// public:
//     int depth(TreeNode* root)
//     {
//         return !root? 0 :  1+max(depth(root->left) ,depth(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root)
//     { 
//        return !root ? 0 : max( depth(root->left) + depth(root->right),  max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)) );
//     }
// };


//method 3

