class Solution {
    int gtimer=1;
    vector<vector<int>>ans;
    void dfs(int i,int parent,vector<vector<int>>&adj,vector<int>&low,vector<int>&time,vector<bool>&vis){
        vis[i]=true;
        low[i]=time[i]=gtimer;
        gtimer++;
        for(auto &it:adj[i]){
            if(parent==it)continue;
            if(!vis[it]){
                dfs(it,i,adj,low,time,vis);
                low[i]=min(low[it],low[i]);
                //if low it <time i that means it can be reached so this is not a bridge 
                if(low[it]>time[i])ans.push_back({i,it});
            }else low[i]=min(low[it],low[i]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>low(n);
        vector<int>time(n);
        vector<vector<int>>adj(n);
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        dfs(0,-1,adj,low,time,vis);
        return ans;
    }
};
