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
struct TreeNode* minValueNode(struct TreeNode * node)
{
	struct TreeNode * current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
	if (!root)
		return root;
 
    // find node to remove
    if (key < root->val)
        root->left = deleteNode(root->left, key);

  	else if (key > root->val)
        root->right = deleteNode(root->right, key);

    // node found
    else
    {
        if (root->left == NULL) // no left child
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) // no right child
        {
    		struct TreeNode *temp = root->left;
    		free(root);
    		return temp;
        }
        
        // if there are two children:
        // find successor, exchange values and remove the one we exchanged
        struct TreeNode * temp = minValueNode(root->right);
        root->val = temp->val;
 
        root->right = deleteNode(root->right, temp->val);   // once swap then it will be deleted by first few conditions
    }
    return root;
}
};
/*  
   Method 2

   class Solution {
public:
    int findminfromright(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(root->right==nullptr){
                return root->left;
            }else if(root->left==nullptr){
                return root->right;
            }else{
			    //replace the root value by find the minimum val from right side 
                root->val=findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
   
};
*/