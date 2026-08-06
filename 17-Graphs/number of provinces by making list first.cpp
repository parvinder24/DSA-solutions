class Solution {
public:
    void helper(vector<int>adj[],vector<int>&visited,int node){
        visited[node]=1;
        //so now we would be traversing the neighbours of the node
        for(auto it:adj[node]){
            if(!visited[it]){
                helper(adj,visited,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //convert the matrix to adjaceny list
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(isConnected[i][k]){
                    adj[i].push_back(k);
                    adj[k].push_back(i);
                }
            }
        }
        //so now list has been created 
        int provinces=0;
        vector<int>visited(n,0);
        //ok so now we would traverse all the nodes
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                //then traverse all of the component it is in
                helper(adj,visited,i);
            }
        }
        return provinces;
    }
};