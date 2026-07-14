class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,-1));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!pq.empty()){
            auto [curr,p]=pq.top();
            auto [r,c]=p;
            pq.pop();
            if(r==n-1&&c==n-1)return curr;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<n&&vis[nr][nc]==-1){
                    vis[nr][nc]=1;
                    pq.push({max(grid[nr][nc],curr),{nr,nc}});
                }
            }
        }
        return -1;
    }
};
