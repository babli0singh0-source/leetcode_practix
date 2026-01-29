class Solution {
public:
    long long sd(int s, int t, vector<vector<pair<int,int>>>& adj) {
        priority_queue<pair<long long,int>, 
            vector<pair<long long,int>>, 
            greater<pair<long long,int>>> pq;

        vector<long long> dist(26, LLONG_MAX);
        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == t) return d;

            for (auto &v : adj[u]) {
                int nxt = v.first;
                int w = v.second;
                if (dist[nxt] > d + w) {
                    dist[nxt] = d + w;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        return -1;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>>adj(26);
        
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        map<pair<int,int>,int>mpp;
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i])continue;
            if(mpp.count({source[i]-'a',target[i]-'a'})!=0){
                ans+=mpp[{source[i]-'a',target[i]-'a'}];
                continue;
            }
            long long temp=sd(source[i]-'a',target[i]-'a',adj);
            if(temp==-1)return -1;
            mpp[{source[i]-'a',target[i]-'a'}]=temp;
            ans+=temp;
        }
        return ans;
        
    }
};
