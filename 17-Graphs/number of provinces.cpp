class Solution {
public:
    void helper(vector<vector<int>> &isConnected,vector<int>&visited,int node){
        int n=isConnected.size();
        visited[node]=1;
        for(int k=0;k<n;k++){
            if(isConnected[node][k]==1&& !visited[k]){
                helper(isConnected,visited,k);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++; 
                //now we should traverse all the neighbours of this node
                helper(isConnected,visited,i);
            }
        }
        return provinces;
    }
};