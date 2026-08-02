#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int floor(TreeNode*root,int val){
    int floorval=-1;
    while(root!=NULL){
        if(root->val<val){
            floorval=root->val;
            root=root->right;
        }
        else if(root->val==val){
            floorval=root->val;
            return floorval;
        }
        else{
            root=root->left;
        }
    }
    return floorval;
}

int main() {
	// your code goes here
	TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    int ans=floor(root,7);
    cout<<ans;
    return 0;

}
