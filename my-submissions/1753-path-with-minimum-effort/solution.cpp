class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        int mini=INT_MAX;
        while(!q.empty()){
            auto [d, p] = q.top();
            auto [r, c] = p;
            q.pop();
            if(r==n-1&&c==m-1){
                return d;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int temp=abs(heights[nr][nc]-heights[r][c]);
                    temp=max(temp,d);
                    if(dis[nr][nc]>temp){
                        dis[nr][nc]=temp;
                        q.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

