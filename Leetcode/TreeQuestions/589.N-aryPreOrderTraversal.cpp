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
    void PreOrder(Node* node, vector<int>& v){
        if (node == nullptr)
            return;
        v.push_back(node->val);
        for(auto child:node->children){
            PreOrder(child,v);
        }
        
    }
    vector<int> preorder(Node* root) {
        vector<int> v;
        PreOrder(root,v);
        return v; 
    }
};