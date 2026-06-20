class Solution {
    long long dfs(int i,vector<long long>&value,vector<vector<int>>&adj,vector<int>& baseTime){
        if(value[i]!=-1)return value[i];
        long long maxi=LLONG_MIN;
        long long mini=LLONG_MAX;
        for(auto &it:adj[i]){
            long long child=dfs(it,value,adj,baseTime);
            maxi=max(maxi,child);
            mini=min(mini,child);
        }
        long long calc=maxi+maxi-mini+(long long)baseTime[i];
        return value[i]=calc;
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<long long>value(n,-1);
        for(int i=0;i<n;i++){
            if(adj[i].size()==0){
                value[i]=(long long)baseTime[i];
            }
        }
        dfs(0,value,adj,baseTime);
        return value[0];
    }
};
