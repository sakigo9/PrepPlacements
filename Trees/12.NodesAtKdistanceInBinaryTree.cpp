#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
vector<int> v;
vector<int> printNnodes(Node* root,int k){
    if(root==NULL && k<0) return{};
    
    if(k==1) {
        v.push_back(root->data);
        return v;
    }
    printNnodes(root->left,k-1);
    printNnodes(root->right,k-1);
    
}

int printKnode(Node* node,Node* target,int k){
    if(node==NULL) return -1;
    if(node==target){
        printNnodes(node,k);
        return 0;
    }
    int dl=printKnode(node->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            v.push_back(node->data);
        }else{
            printNnodes(node->right,dl-k-1);
        }
        return dl+1;
    }
    int dr=printKnode(node->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            v.push_back(node->data);
        }else{
            printNnodes(node->left,dr-k-1);
        }
        return dr+1;
    }
}

int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    printKnode(root,root->left,1);
    for(auto i:v){
        cout<<i<<" ";
    }
}