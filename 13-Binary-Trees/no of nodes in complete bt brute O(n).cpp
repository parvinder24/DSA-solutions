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
    int count=0;
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        helper(root->left);
        helper(root->right);
        count++;
        return count;
    }
    int countNodes(TreeNode* root) {
        //first let's forget about the tc 
        //so we just need to do a traversal 
        helper(root);
        return count;
    }
};