class Solution {
    bool check (int node,int edge){
        if(node<3)return true;
        int cal=(node*(node-1))/2;
        return cal==edge;

    }
    bool bfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        queue<int>q;
        vis[i]=1;
        int nodecount=1;
        q.push(i);
        int edgecount=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto &it:adj[x]){
                edgecount++;
                if(vis[it]==-1){
                    q.push(it);
                    nodecount++;
                    vis[it]=1;
                }
            }
        }
        edgecount/=2;
        return check(nodecount,edgecount);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(bfs(i,adj,vis))count++;
            }
        }
        return count;
    }
};
