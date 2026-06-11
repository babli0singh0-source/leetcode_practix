class Solution {
    long long power(long long a, long long b) {
        long long mod = 1000000007;
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        int maxdepth=0;
        for(auto &it:adj[node]){
            if(!vis[it]){
                maxdepth=max(maxdepth,1+dfs(it,adj,vis));
            }
        }
        return maxdepth;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+2);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+2,0);
        int depth=dfs(1,adj,vis);
        int ans=(int)power(2,depth-1);
        return ans;
    }
};
//using binomial expansion, since the number of 1s should be odd, then for a path length of n, the total possibilities are :
//nC1 + nC3 + nC5+ ... + nC(2x+1). this is equal to 2^n-1
