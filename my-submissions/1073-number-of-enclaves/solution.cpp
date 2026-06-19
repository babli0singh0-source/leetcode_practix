class Solution {
    void mark(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int n,int m,int dr[],int dc[]){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(vis[i][0]==0&&grid[i][0]==1){
                mark(i,0,vis,grid,n,m,dr,dc);
            }
            if(vis[i][m-1]==0&&grid[i][m-1]==1){
                mark(i,m-1,vis,grid,n,m,dr,dc);
            }
        }
        for(int i=0;i<m;i++){
            if(vis[0][i]==0&&grid[0][i]==1){
                mark(0,i,vis,grid,n,m,dr,dc);
            }
            if(vis[n-1][i]==0&&grid[n-1][i]==1){
                mark(n-1,i,vis,grid,n,m,dr,dc);
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
