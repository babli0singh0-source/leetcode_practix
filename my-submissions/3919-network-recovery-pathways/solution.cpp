class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>>adj(n);
        int left=INT_MAX;
        int right=0;
        vector<int>indeg(n,0);
        for(auto &it:edges){
            if(online[it[0]]&&online[it[1]]){
                adj[it[0]].push_back({it[1],it[2]});
                indeg[it[1]]++;
                left=min(left,it[2]);
                right=max(right,it[2]);
            }
        }
        queue<int>q;
        for(int i=1;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &[v,w]:adj[u]){
                indeg[v]--;
                if(v&&indeg[v]==0)q.push(v);
            }
        }
        auto check=[&](int mid)->bool{
            vector<long long> dp(n,LLONG_MAX/2);
            vector<int>currdeg=indeg;
            dp[0]=0;
            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(u==n-1){
                    return dp[u]<=k;
                }
                for(auto &[x,y]:adj[u]){
                    if(y>=mid){
                        dp[x]=min(dp[x],dp[u]+y);
                    }
                    currdeg[x]--;
                    if(currdeg[x]==0){
                        q.push(x);
                    }
                }
            }
            return false;
        };
        if(!check(left)){
            return -1;
        }
        while(left<=right){
            int mid=(left+right)/2;
            if(check(mid)){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return right;
    }
};
