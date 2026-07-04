class Solution {
public:
    void DFS(vector<vector<pair<int,int>>>& adj,int u,vector<bool>& visited,int &minLen){
        visited[u]=true;
        for(auto &ele: adj[u]){
            int v=ele.first;
            int d=ele.second;
            minLen=min(minLen,d);
            if(!visited[v]) DFS(adj,v,visited,minLen);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &ele: roads){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }
        vector<bool> visited(n+1,false);
        int minLen=INT_MAX;
        DFS(adj,1,visited,minLen);
        return minLen;
    }
};
