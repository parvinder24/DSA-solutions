#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//so we would use the same approach and same data structures but just would not check that if our col has already been stored we would just everytime write the value in our col so that would correspond to the bottom view
vector<int>helper(Node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>mpp;//it would store the col and value in it
    queue<pair<Node*,int>> todo; //it would store the node and it's vertical
    todo.push({root,0});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node* nod=p.first;
        int x=p.second;
        mpp[x]=nod->data;
        if(nod->left){
            todo.push({nod->left,x-1});
        }
        if(nod->right){
            todo.push({nod->right,x+1});
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
	// your code goes here
	Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);
    vector<int>answer;
    answer=helper(root);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
