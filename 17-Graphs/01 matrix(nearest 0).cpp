class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            //now we will be doing bfs with these elements in the queue
            int delrow[4]={0,-1,0,1};
            int delcol[4]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nx=x+delrow[i];
                int ny=y+delcol[i];
                if(nx>=0&&nx<m && ny>=0&&ny<n && !vis[nx][ny]){
                    dist[nx][ny]=steps+1;
                    vis[nx][ny]=1;
                    q.push({{nx,ny},steps+1});
                }
            }
        }
        return dist;
    }
};