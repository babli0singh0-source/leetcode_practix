class Solution {
    bool dfs(vector<int>&vis,vector<int>&pathvis,int i,vector<vector<int>>& graph){
        vis[i]=1;
        pathvis[i]=1;
        for(auto &it:graph[i]){
            if(vis[it]==0){
                if(dfs(vis,pathvis,it,graph))return true;
            }else if(pathvis[it]==1)return true;
        }
        pathvis[i]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(vis,pathvis,i,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(pathvis[i]==0)ans.push_back(i);
        }
        return ans;   
    }
};
