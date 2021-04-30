#include<vector>
#include<iostream>
#include<set>
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
    void Make(TreeNode* root,set<int>& pq){
        if(root==NULL) return;
        
        Make(root->left,pq);
        pq.insert(root->val);
        Make(root->right,pq);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL) return -1;
        set<int> s;
        Make(root,s);
        
        if(s.size() >= 2)
		{
			auto itr = s.begin();
			advance(itr, 1);
			return *itr;
		}
	   return -1;
    }
};