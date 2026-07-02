class Solution {
    void helper(vector<vector<int>>&adj,int node,vector<int>&vec,string &labels,vector<int>&ans,vector<int>&vis){
        vis[node]=1;
        // if(adj[node].size()==1){
        //     ans[node]=1;
        //     vec[labels[node]-'a']++;
        //     return;
        // }
        auto x=labels[node]-'a';
        vec[x]++;
        ans[node]=1;
        for(auto &it:adj[node]){
            if(vis[it]!=-1)continue;
            int temp1=vec[x];
            helper(adj,it,vec,labels,ans,vis);
            int temp2=vec[x];
            ans[node]+=temp2-temp1;
        }
        return;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vec(26,0);
        vector<int>ans(n,0);
        vector<int>vis(n,-1);
        helper(adj,0,vec,labels,ans,vis);
        return ans;
    }
};

