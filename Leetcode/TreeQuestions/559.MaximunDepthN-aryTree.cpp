/*
RECURSIVE SOLUTION
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int ans = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            ans = max(ans, maxDepth(root->children[i]));
        }
 
        return ans + 1;
    }
};

*/
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
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int n=q.size();
            
            while(n--){
                Node* node=q.front();
                q.pop();
                
                for(auto child: node->children){
                    q.push(child);
                }
            }
            c++;
        }
        return c;
    }
};