class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //it is nearly same as rotten oranges problem
        if(color==image[sr][sc]){
            return image;
        }
        int m=image.size();
        int n=image[0].size();
        int origcolor=image[sr][sc];
        queue<pair<int,int>> samecolor;
        samecolor.push({sr,sc});
        image[sr][sc]=color;
        //bfs
        while(!samecolor.empty()){
            int k=samecolor.size();
            int dx[4]={0,-1,0,+1};
            int dy[4]={-1,0,+1,0};
            for(int i=0;i<k;i++){
                int x=samecolor.front().first;
                int y=samecolor.front().second;
                samecolor.pop();
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx>=0 && nx<m && ny>=0 && ny<n){
                        if(image[nx][ny]==origcolor){
                            image[nx][ny]=color;
                            samecolor.push({nx,ny});
                        }
                    }
                }
            }
        }
        return image;
    }
};