#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

   class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> p;
            
            int n=q.size();
            
            while(n--){
                Node* node=q.front();
                q.pop();
                p.push_back(node->val);
                for (auto child : node->children)
                    q.push(child);
            }
            res.push_back(p);
        }
        return res;
    }
};