/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //so the approach is kind of clever like what we have to do is that we will be finding these nodes and traversing the tree wherever we split is the lca of those two nodes and if we are not able to move any side that means we are at one of the nodes so return that node
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ans=nullptr;
        if(root==p || p==q){
            return root;
        }
        while(root){ 
            if(p->val>root->val && q->val>root->val){
                root=root->right;
            }
            else if(p->val<root->val && q->val<root->val){
                root=root->left;
            }
            else if(root->val==p->val || root->val==q->val){
                return root;
            }
            else{
                return root;
            }
        }
        return ans;
    }
};