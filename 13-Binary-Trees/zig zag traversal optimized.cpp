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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        bool lefttoright=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                //instead of storing then checking the count we can directly store the elements in correct for that we just need to change the index if it is left to right no neeed to change otherwise for right to left we need to change the index at value to be stored by index-i-1
                int index=0;
                if(lefttoright){
                    index=i;
                }
                else{
                    index=size-i-1;
                }
                level[index]=node->val;
            }
            ans.push_back(level);
            lefttoright=!lefttoright;
        }
        return ans;
    }
};