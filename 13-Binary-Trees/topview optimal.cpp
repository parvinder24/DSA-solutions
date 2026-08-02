#include <bits/stdc++.h>
using namespace std;
//topview is a bit of simple than the vertical order traversal we just need to store the value and it's vertical
struct Node {
    // Value stored in the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;
    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


vector<int>helper(Node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int> mpp;//it stores the vertical and the value
    queue<pair<Node*,int>>todo;//it stores the node and the vertical
    todo.push({root,0});
    while(!todo.empty()){
        auto it=todo.front();
        todo.pop();
        Node* nod=it.first;
        int x=it.second;
        //if we haven't seen the vertical before into the map then we would push the value with it's vertical
        if(mpp.find(x)==mpp.end()){
            mpp[x]=nod->data;
        }
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
 