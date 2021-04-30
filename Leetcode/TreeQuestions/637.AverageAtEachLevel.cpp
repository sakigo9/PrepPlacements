/*
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans;
        queue <TreeNode*> q;
        q.push(root);
        
        //Level order traversal
        while(!q.empty()){
            long long int size = q.size(), sum = 0;
            
            for(int i = 0; i < size; i++){
                auto temp = q.front();
                q.pop();
                
                sum += temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans.push_back((double)sum/size);
        }
        return ans;
    }

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
    double sum(vector<double> v){
        double sum=0;
        for(auto i : v){
            sum+=i;
        }
        return sum;
    }
    void Level(TreeNode* root,vector<vector<double>>& v){
        
        if(root==nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
    
    while(!q.empty())
    {
        vector<double> temp;
        int n =q.size();

        for(int i = 1; i <= n; i++)
        {
             TreeNode* t = q.front();
             q.pop();
             temp.push_back(t -> val);
             
             if(t -> left)
                 q.push(t -> left);
             if(t -> right)
                 q.push(t -> right);
        }
        v.push_back(temp);
    }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> v;
        Level(root,v);
        vector<double> res;
        for(auto i:v){
            double s=sum(i);
            double p=s/i.size();
            res.push_back(p);
            
        }
        return res;
    }
};