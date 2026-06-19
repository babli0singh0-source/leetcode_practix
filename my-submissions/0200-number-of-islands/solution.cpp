class Solution {
    vector<int> dr={1,0,-1,0};
    vector<int> dc={0,-1,0,1};
    void bfs(int row,int col,int n,int m,vector<vector<char>>& grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return ans;
    }
};
