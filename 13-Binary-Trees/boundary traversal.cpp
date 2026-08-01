#include <bits/stdc++.h>
using namespace std;
//now we are solving the question of boundary traversal(int clockwise dirn) here so the approach we are going to follow is that first we would traverse the right boundary by going left each time if left is not null else go to it's right leaving the leafs , then we would add the leafs into the answer data structure by traversing the tree again from starting the similary traverse the left boundary and add it to answer from the last 
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isleaf(Node*root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
void rightboundary(Node*root, vector<int>&answer){
    Node* curr=root->right;
    while(curr){
        if(!isleaf(curr)){
            answer.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
}
//now let's add the leafs
void addleafs(Node*root,vector<int>&answer){
    if(isleaf(root)){
        answer.push_back(root->data);
        return;
    }
    if(root->right){
        addleafs(root->right,answer);
    }
    if(root->left){
        addleafs(root->left,answer);
    }
}
//now the left boundary
void leftboundary(Node*root,vector<int>&answer){
    vector<int>temp;
    Node*curr=root->left;
    while(curr){
        if(!isleaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        answer.push_back(temp[i]);
    }
}

int main() {
	// your code goes here
	// Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int>answer;
    if(root==NULL){
        return 0;
    }
    if(!isleaf(root)){
        answer.push_back(root->data);
    }
	rightboundary(root,answer);
	addleafs(root,answer);
	leftboundary(root,answer);
	for(int i=0;i<answer.size();i++){
	    cout<<answer[i]<<" ";
	}
    return 0;
}
