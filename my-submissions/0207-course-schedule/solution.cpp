class Solution {
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto &it:adj[i]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,pathvis))return true;
            }else if(pathvis[it]==1)return true;
            
        }
        pathvis[i]=0;
        return false ;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,pathvis)==true)return false;
            }
        }
        return true;
    }
};
