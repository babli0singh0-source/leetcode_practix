class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};
        int n=grid.size();
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==0)q.push({1,{0,0}});
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=1;
        while(!q.empty()){
            auto [d, p] = q.front();
            auto [r, c] = p;
            if(r==n-1&&c==n-1){
                return dis[r][c];
            }
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==0){
                    if(dis[nr][nc]>1+dis[r][c]){
                        dis[nr][nc]=1+dis[r][c];
                        q.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
