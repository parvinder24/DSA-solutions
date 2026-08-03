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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //so the mechanism we are going to follow here is that we would traverse the map till we don't reach any nullptr and then there we would insert the give value/node , the approach is if the given value val is smaller go to left and if given value val is greater go to right
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode*curr=root;
        TreeNode*father=root;
        while(curr){
            father=curr;
            if(val>curr->val){
                //then we go right
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        //so now we would be at nullptr we need to create this as the node
        if(val>father->val){
            TreeNode* nod=new TreeNode(val);
            father->right=nod;
        }
        else{
            TreeNode* nod=new TreeNode(val);
            father->left=nod;
        }
        return root;
    }
};