class Solution {
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    void bfs(vector<vector<int>>&grid,vector<vector<int>>&dis,int n){
        vector<vector<int>>vis(n,vector<int>(n,-1));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                    dis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [currdis,p]=q.front();
            auto [r,c]=p;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<n){
                    if(vis[nr][nc]==-1||dis[nr][nc]>currdis+1){
                        vis[nr][nc]=1;
                        q.push({currdis+1,{nr,nc}});
                        dis[nr][nc]=currdis+1;
                    }
                }
            }
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(n,-1));
        bfs(grid,dis,n);
        pq.push({dis[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            auto [cost,q]=pq.top();
            auto [r,c]=q;
            pq.pop();
            if(r==n-1&&c==n-1){
                return cost;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<n&&vis[nr][nc]==-1){
                    vis[nr][nc]=1;
                    int temp=min(cost,dis[nr][nc]);
                    //cout<<cost<<endl;
                    pq.push({temp,{nr,nc}});
                }
            }  
        }
        return 0;
    }
};
