class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited=grid;//just bcoz we should not change the data given 
        int total=0;
        int count=0;
        int minutes=0;
        queue<pair<int,int>>rotten;//to stor the positions of rotten orangesd
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //counting total number of orangs
                if(grid[i][j]!=0){
                    total++;
                }
                if(grid[i][j]==2){
                visited[i][j]=2;
                rotten.push({i,j});  
                }
            }
        }
        int dy[4]={-1,0,+1,0};
        int dx[4]={0,-1,0,+1};
        //so now we have some rotten orangs in queue so now our task is to rott the adj 
        while(!rotten.empty()){
            //bfs traversal
            int k=rotten.size();
            count+=rotten.size();
            for(int i=0;i<k;i++){
                int fc=rotten.front().first;
                int sc=rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nx=fc+dx[i];
                    int ny=sc+dy[i];
                    if(nx>=0 &&nx<m && ny>=0 && ny<n){
                        if(visited[nx][ny]==1){
                            visited[nx][ny]=2;
                            rotten.push({nx,ny});
                        }   
                    }   
                }
            }
            if(!rotten.empty()){
                minutes++;
            }
        }
        if(total==count){
            return minutes;
        }
        return -1;
    }
};