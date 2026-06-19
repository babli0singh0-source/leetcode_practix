class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            for(auto &it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        if(q.empty())return {};
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(ans.size()!=n)return {};
        // for(int i=0;i<n;i++){
        //     if(indegree[i]!=0)return {};
        // }
        return ans;
    } 
};     
