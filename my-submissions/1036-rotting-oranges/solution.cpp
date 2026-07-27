class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                if (grid[i][j]==1)fresh++;
            }
        }
        int dr[]={0,0,-1,1};
        int dc[]={1,-1,0,0};
        int ans=0;
        while(!q.empty()){
            auto [time,p]=q.front();
            auto [r,c]=p;
            q.pop();
            ans=max(ans,time);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==-1&&grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    fresh--;
                    q.push({time+1,{nr,nc}});
                }
            }
        }

        return fresh==0?ans:-1;
    }
};
