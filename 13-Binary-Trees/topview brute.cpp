#include <bits/stdc++.h>
using namespace std;
//for top view of binary tree i think we definitely would have to traverse all the nodes so that we would do by level order traversal 
//ok so i think i would allot the vertical and row nos to all the nodes 
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

vector<int> helper(Node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node* nod=p.first;
        int x=p.second.first;//col 
        int y=p.second.second;//row/level
        nodes[x][y].insert(nod->data);
        if(nod->left){
            todo.push({nod->left,{x-1,y+1}});
        }
        if(nod->right){
            todo.push({nod->right,{x+1,y+1}});
        }
    }
    //so now we have all the nodes with their row and cols mentioned 
    //now we just need to iterate throught he nodes and only push the first multinode of every columns first row
    
    for(auto p:nodes){
        ans.push_back(*p.second.begin()->second.begin());
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
    vector<int>answer=helper(root);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;

}
