// class Solution {
//     int mod=1e9+7;
//     void update(int i,int j,int ni,int nj,int n,vector<vector<pair<int,int>>>&dp){
//         if(ni<0||nj<0||dp[ni][nj].first==0)return;
//         if(dp[ni][nj].first>dp[i][j].first){
//             dp[i][j]=dp[ni][nj];
//         }else if(dp[ni][nj].first==dp[i][j].first){
//             dp[i][j].second+=dp[ni][nj].second;
//             if(dp[i][j].second>=mod)dp[i][j].second-=mod;
//         }
//     }
// public:
//     vector<int> pathsWithMaxScore(vector<string>& board) {
//         int n=board.size();
//         int m=board.size();
//         int dr[]={-1,-1,0};
//         int dc[]={-1,0,-1};
//         vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(m,{0,0}));
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
//                 if((i==n-1&&j==m-1)||board[i][j]=='X')continue;
//                 for(int k=0;k<3;k++){
//                     int ni=i+dr[k];
//                     int nj=j+dc[k];
//                     update(i,j,ni,nj,n,dp);
//                 }
//                 if(dp[i][j].first!=0){
//                     dp[i][j].first+=(board[i][j]=='E'?0:board[i][j]-'0');
//                 }
//             }
//         }
//         return {dp[0][0].first,dp[0][0].second};
//     }
// };



class Solution {
private:
    int mod = (int)1e9 + 7;

public:
    void update(vector<vector<pair<int,int>>>& dp, int n, int x, int y, int u, int v) {
        if (u >= n || v >= n || dp[u][v].first == -1) {
            return;
        }
        if (dp[u][v].first > dp[x][y].first) {
            dp[x][y] = dp[u][v];
        } else if (dp[u][v].first == dp[x][y].first) {
            dp[x][y].second += dp[u][v].second;
            if (dp[x][y].second >= mod) {
                dp[x][y].second -= mod;
            }
        }
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
                    update(dp, n, i, j, i + 1, j);
                    update(dp, n, i, j, i, j + 1);
                    update(dp, n, i, j, i + 1, j + 1);
                    if (dp[i][j].first != -1) {
                        dp[i][j].first +=
                            (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }
        return dp[0][0].first == -1 ? vector<int>{0, 0}:vector<int>{dp[0][0].first,
        dp[0][0].second};
    }
};
