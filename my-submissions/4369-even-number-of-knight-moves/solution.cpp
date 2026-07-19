class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dr[]={-2,-2,-1,+1,+2,+2,+1,-1};
        int dc[]={-1,+1,+2,+2,+1,-1,-2,-2};
        vector<vector<int>>vis(8,vector<int>(8,-1));
        vis[start[0]][start[1]]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{start[0],start[1]}});
        while(!q.empty()){
            auto [dis,p]=q.front();
            auto [r,c]=p;
            q.pop();
            if(r==target[0]&&c==target[1]){
                if(dis%2==0)return true;
            }
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<8&&nc<8&&vis[nr][nc]==-1){
                    q.push({dis+1,{nr,nc}});
                    vis[nr][nc]=dis+1;
                }
            }
        }
        return false;
    }
};
