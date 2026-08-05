#include <bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int>&result,vector<int>adj[],vector<int>&visited){
    //mark the current as visited
    visited[v]=1;
    result.push_back(v);//push the node into the result
    for(auto it:adj[v]){
        if(!visited[it]){
            dfs(it,result,adj,visited);
        }
    }
}
int main() {
	// your code goes here
	int n= 5;

    // Adjacency list
    vector<int> adj[n];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};
    vector<int>visited(n,0);
    vector<int>result;
    dfs(0,result,adj,visited);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}
