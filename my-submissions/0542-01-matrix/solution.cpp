class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,{j,0}});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second.first;
            int steps=q.front().second.second;
            q.pop();
            ans[r][c]=steps;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nc>=0&&nc<m&&nr>=0&&nr<n&&vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,{nc,steps+1}});
                }
            }
        }
        return ans;
    }
};
