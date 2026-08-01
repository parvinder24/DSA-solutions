/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool isleaf(TreeNode*root){
    //     if(root->left==NULL && root->right==NULL){
    //         return true;
    //     }
    //     return false;
    // }
    int countleft(TreeNode* root){
        TreeNode* curr=root;
        int leftht=0;
        while(curr){
            leftht++;
            curr=curr->left;
        }
        return leftht;
    }
    int countright(TreeNode*root){
        TreeNode*curr=root;
        int rightht=0;
        while(curr){
            rightht++;
            curr=curr->right;
        }
        return rightht;
    }
    int helper(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int right=countright(root);
        int left=countleft(root);
        if(right==left){
            //means it is complete bt
            return ((1<<left)-1);
        }
        else{
            return 1+helper(root->left) +helper(root->right);
        }
        return 0;
    }
    int countNodes(TreeNode* root) {
        //so the concept is that we would check if a subtree or even the tree is a complete bt if yes then would retun the result we got else check the subtrees recurssively
        return helper(root);


    }
};