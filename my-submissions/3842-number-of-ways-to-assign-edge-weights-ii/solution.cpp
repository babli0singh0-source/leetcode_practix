class Solution {
    long long power(long long a,long long b){
        long long ans=1;
        long long mod=1000000007;
        while(b){
            if(b&1)ans=ans*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return ans;
    }
    int lca(int u,int v,vector<vector<int>>&bl,vector<int>&depth){
        if(depth[u]<depth[v])swap(u,v);
        int diff=depth[u]-depth[v];
        for(int j=17;j>=0;j--){
            if(diff&(1<<j))u=bl[u][j];// if 2^j contained in diff
        }
        if(u==v)return u;
        //// bring u to same depth as v
        for(int j=17;j>=0;j--){
            if(bl[u][j]!=bl[v][j]){
                u=bl[u][j];
                v=bl[v][j];
            }
        }
        return bl[u][0];
    }
    void dfs(vector<vector<int>>&adj,int node,int parent,vector<vector<int>>&bl,vector<int>&depth){
        bl[node][0]=parent;
        for(auto &it:adj[node]){
            if(it!=parent){
                depth[it]=depth[node]+1;
                dfs(adj,it,node,bl,depth);
            }
        }
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size();
        vector<vector<int>>adj(n+2);
        vector<vector<int>>bl(n+2,vector<int>(18));
        vector<int>depth(n+2,0);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(adj,1,0,bl,depth);
        for(int j=1;j<18;j++){
            for(int i=1;i<=n+1;i++){
                bl[i][j]=bl[bl[i][j-1]][j-1];
            }
        }
        vector<int>ans;
        for(auto &it:queries){
            int u=it[0];
            int v=it[1];
            if(u==v){
                ans.push_back(0);
                continue;
            }
            int L=lca(u,v,bl,depth);
            int dist=depth[u]+depth[v]-2*depth[L];
            ans.push_back(power(2,dist-1));
        }
        return ans;
    }
};
    // int helper(int node,int final,vector<vector<int>>&adj,vector<int>&vis,vector<vector<int>>&dp){
    //     if(node==final)return 0;
    //     if(dp[node][final]!=-1)return dp[node][final];
    //     vis[node]=1;
    //     for(auto &it:adj[node]){
    //         if(!vis[it]){
    //             int dis=helper(it,final,adj,vis,dp);
    //             if(dis!=-1)return dp[node][final]=dis+1;
    //         }
    //     }
    //     return dp[node][final]=-1;
    // }
