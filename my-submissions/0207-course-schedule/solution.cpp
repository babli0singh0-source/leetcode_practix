class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &it:adj[curr]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        return (ans.size()==numCourses);
    }
};
