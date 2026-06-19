class Solution {
    void mark(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board,int n,int m,int dr[],int dc[]){
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
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&board[nr][nc]=='O'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(vis[i][0]==0&&board[i][0]=='O'){
                mark(i,0,vis,board,n,m,dr,dc);
            }
            if(vis[i][m-1]==0&&board[i][m-1]=='O'){
                mark(i,m-1,vis,board,n,m,dr,dc);
            }
        }
        for(int i=0;i<m;i++){
            if(vis[0][i]==0&&board[0][i]=='O'){
                mark(0,i,vis,board,n,m,dr,dc);
            }
            if(vis[n-1][i]==0&&board[n-1][i]=='O'){
                mark(n-1,i,vis,board,n,m,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(vis[i][j]==0&&board[i][j]=='O'){
                    vis[i][j]=1;
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};
