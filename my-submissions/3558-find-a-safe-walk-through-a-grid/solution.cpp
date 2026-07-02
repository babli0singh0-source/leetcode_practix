class Solution {

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        priority_queue<pair<int,pair<int,int>>>pq;
        if(grid[0][0]==1)health =health-1;
        pq.push({health,{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            auto [currhealth,p]=pq.top();
            auto [r,c]=p;
            pq.pop();
            if(currhealth<1)continue;
            if(r==n-1&&c==m-1)return true;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<n&&nc<m&&nr>=0&&nc>=0&&vis[nr][nc]==-1){
                    vis[nr][nc]=1;
                    if(grid[nr][nc]==1)pq.push({currhealth-1,{nr,nc}});
                    else pq.push({currhealth,{nr,nc}});
                    
                }
            }

        }
        return false;
    }
};
