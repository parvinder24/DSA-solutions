#include <bits/stdc++.h>
using namespace std;
//approach is basic and simple 
int noofcomponents(int nodes,vector<vector<int>>&edges){
    //make a graph using list 
    vector<int>adj[nodes];
    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    //graph is created 
    vector<int> visited(nodes,0);
    int components=0;
    //now traverse all the nodes in the graph 
    for(int i=0;i<nodes;i++){
        
        if(!visited[i]){
            //so a new component is going to begin
            components++;
            //visit the neighbours of this node
            queue<int>q;
            q.push(i);
            visited[i]=1;
            //so basically now our traget is to visit the all the neighbours of this node and mark them as visited =1 
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto &nbr:adj[node]){
                    if(!visited[nbr]){
                        visited[nbr]=1;
                        q.push(nbr);//all these neighbours which have been pushed now they will be used again due to while for again marking the nodes which are theri neighbours as 1
                    }
                }
            }
        }
    }
    return components;
}

int main() {
	// your code goes here
	int n=7;
	vector<vector<int>>edges={{0,1},{1,2},{2,3},{4,5}};
	cout<<noofcomponents(n,edges);
    return 0;
}
