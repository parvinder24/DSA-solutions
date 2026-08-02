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
    //so this time we are going to store the rows instead of the columns and the approach would be that for each row or node just overwrite the value and it would give us the right view only since we are doing level order traversal
    vector<int> helper(TreeNode* root){
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>mpp;//first one would store the row and the second one would store the value
        queue<pair<TreeNode*,int>>todo;//the first one would be storing the node and the second one would be storing the row
        todo.push({root,0});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* nod=p.first;
            int y=p.second;//so this y is row number 
            //now we would be storing the row number with the value
            mpp[y]=nod->val;
            if(nod->left){
                todo.push({nod->left,y+1});
            }
            if(nod->right){
                todo.push({nod->right,y+1});
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {        
        return helper(root);   
    }
};