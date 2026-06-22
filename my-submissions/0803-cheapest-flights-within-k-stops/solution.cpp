class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,src}});
        while(!q.empty()){
            auto [count,p]=q.front();
            auto [d,node]=p;
            q.pop();
            if(count>k)continue;
            for(auto &it:adj[node]){
                auto [currnode,price]=it;
                if(price+d<dis[currnode]&&count<=k){
                    dis[currnode]=price+d;
                    q.push({count+1,{dis[currnode],currnode}});
                }
            }
        }
        if(dis[dst]==INT_MAX)return -1;
        return dis[dst];
    }
};
