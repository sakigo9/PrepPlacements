#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=right=NULL;
    }
};
void RightView(Node* root,vector<vector<int>>& v){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> part;
        while(n--){
            Node* node=q.front();
            q.pop();
            if(node->val){
                part.push_back(node->val);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        v.push_back(part);
    }
}

int main(){
    Node* root =new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->left->left=new Node(7);
    vector<vector<int>> v;
    RightView(root,v);
    
    for(auto i:v){
        int k=i.size();
        cout<<i[k-1]<<" ";
    }
}