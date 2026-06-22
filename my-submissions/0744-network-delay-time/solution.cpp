class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        q.push({0,k});
        dis[k]=0;
        while(!q.empty()){
            auto [t,node]=q.top();
            q.pop();
            for(auto &it:adj[node]){
                auto [curr,time]=it;
                if(dis[curr]>time+t){
                    dis[curr]=time+t;
                    q.push({dis[curr],curr});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
