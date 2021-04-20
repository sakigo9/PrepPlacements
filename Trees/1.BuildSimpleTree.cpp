#include<iostream>

using namespace std;
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};


int main(){
    struct Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
}