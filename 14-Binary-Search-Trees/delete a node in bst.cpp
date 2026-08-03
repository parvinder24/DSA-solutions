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
    //we will have to create some functions
    //helper function will be the one which will delte the node and rearrange the nodes as required
    //now we would write the function for finding the righmost child
    TreeNode*findrightmostchild(TreeNode*root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode*root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        //so if none of them is pointing to null
        //so we would need to connect the rightchild of tree to righmost position of leftchild
        TreeNode*righchild=root->right;
        TreeNode* rightmostchild=findrightmostchild(root->left);
        rightmostchild->right=righchild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        //so now we would run the main function with handling all the edge cases
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode*dummy=root;
        //we are finding the node and there only would delete not seperately
        while(root){
            //going to the left side
            if(key<root->val){
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                //moving to the right side
                //ok so here also we would follow the same procedure go to the node whose next is the key containg node call the helper function on it and connect the parent to the returned node by helper
                if(root->right!=NULL &&root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};