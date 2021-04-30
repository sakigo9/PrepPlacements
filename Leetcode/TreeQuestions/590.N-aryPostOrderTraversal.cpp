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
    void PostOrder(Node* node, vector<int>& v){
        if (node == nullptr)
            return;
        
        for(auto child:node->children){
            PostOrder(child,v);
        }
        v.push_back(node->val);
        
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        PostOrder(root,v);
        return v; 
    }
};