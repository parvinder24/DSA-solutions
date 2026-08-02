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
    //these left and right view are actually easy to solve we can just go through each level store that and return accordingly fro each level
    vector<vector<int>>helper(TreeNode* root){
        vector<vector<int>>levels;
        if(root==NULL){
            return levels;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode*nod=q.front();
                q.pop();
                level.push_back(nod->val);
                if(nod->left){
                q.push(nod->left);
                }
                if(nod->right){
                q.push(nod->right);
                }
            }
            levels.push_back(level);
            
        }
        return levels;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> probable;
        probable=helper(root);
        vector<int>ans;
        for(auto p:probable){
            ans.push_back(p.back());
        }
        return ans;
    }
};