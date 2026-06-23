class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1000000007;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<long long>time(n,LLONG_MAX);
        vector<int>ways(n,0);
        vector<vector<pair<int,long long>>>adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        q.push({0,0});
        time[0]=0;
        ways[0]=1;
        while(!q.empty()){
            auto [t,curr]=q.top();
            q.pop();
            for(auto &it:adj[curr]){
                auto [nxt,tt]=it;
                if(time[nxt]>t+tt){
                    time[nxt]=t+tt;
                    q.push({time[nxt],nxt});
                    ways[nxt]=ways[curr];
                }else if(time[nxt]==t+tt){
                    ways[nxt]=(ways[nxt]+ways[curr])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
