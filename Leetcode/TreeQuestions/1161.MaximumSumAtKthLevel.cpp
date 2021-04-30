/*
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> pq;
        int ans;
        int sum=INT_MIN;
        int level=1;
        
        pq.push(root);
        
        while(pq.size()!=0){
            int n=pq.size();
            int temp=0;
            
            for(int i=0;i<n;i++){
                TreeNode* x=pq.front();
                pq.pop();
                if(x)temp+=x->val;
                if(x->left)pq.push(x->left);
                if(x->right)pq.push(x->right);
            }
            
            if(sum<temp){
                sum=temp;
                ans=level;
            }
            level++;
        }
        
        return ans;
    }
};
*/
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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--)
            {
                
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            v.push_back(sum);
        }
        int res=*max_element(begin(v),end(v));
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==res){
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};