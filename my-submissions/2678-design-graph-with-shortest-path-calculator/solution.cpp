class Graph {
    vector<vector<pair<int,long long>>>adj;
    int s;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        s=n;
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],1LL*it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],1LL*edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,node1});
        vector<int>dis(s,INT_MAX);
        while(!pq.empty()){
            auto [cost,curr]=pq.top();
            pq.pop();
            if(curr==node2)return cost;
            if(cost>dis[curr])continue;
            for(auto &it:adj[curr]){
                if(cost+it.second<dis[it.first]){
                    pq.push({cost+it.second,it.first});
                    dis[it.first]=cost+it.second;
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
