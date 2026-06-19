class Solution {
    bool dfs(int curr,vector<vector<int>>& graph,vector<int>&vis){
        int color=vis[curr];
        int newcol=color==0?1:0;
        for(auto &it:graph[curr]){
            if(vis[it]==-1){
                vis[it]=newcol;
                if(!dfs(it,graph,vis))return false;
            }else if(vis[it]!=newcol)return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=0;
                if(!dfs(i,graph,vis))return false;
            }
        }
        return true;
    }
};

// class Solution {
//     bool bfs(int ind,vector<vector<int>>& graph,vector<int>&vis){
//         queue<int>q;
//         q.push(ind);
//         while(!q.empty()){
//             int curr=q.front();
//             int color=vis[curr];
//             int newcol=color==0?1:0;
//             q.pop();
//             for(auto &it:graph[curr]){
//                 if(vis[it]==-1){
//                     q.push(it);
//                     vis[it]=newcol;
//                 }else if(vis[it]!=newcol)return false;
//             }
//         }
//         return true;
//     }
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>vis(n,-1);
//         for(int i=0;i<n;i++){
//             if(vis[i]==-1){
//                 vis[i]=0;
//                 if(!bfs(i,graph,vis))return false;
//             }
//         }
//         return true;
//     }
// };

