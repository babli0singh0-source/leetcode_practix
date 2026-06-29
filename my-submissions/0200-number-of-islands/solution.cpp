class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&vis[i][j]==-1){
                    ans++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [r,c]=q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];
                            if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==-1&&grid[nr][nc]=='1'){
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
