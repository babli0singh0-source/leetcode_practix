class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> pq;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<long long>> dist(n, vector<long long>(k + 1, 1e18));
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while(!pq.empty()){
            auto [d, u, cnt] = pq.top();
            pq.pop();
            if(d != dist[u][cnt]) continue;
            if(u == n - 1) return (int)d;
            for(auto &[v, w] : adj[u]){
                int newCnt;
                if(labels[v] == labels[u])
                    newCnt = cnt + 1;
                else newCnt = 1;
                if(newCnt > k) continue;
                long long nd = d + w;
                if(nd < dist[v][newCnt]){
                    dist[v][newCnt] = nd;
                    pq.push({nd, v, newCnt});
                }
            }
        }

        return -1;
    }
};
