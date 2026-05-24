class Solution {
    int helper(int ind,int d,vector<int>& arr,int n,vector<int>&dp){
        int ans=1;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind+1;i<=(min(ind+d,n-1));i++){
            if(arr[ind]<=arr[i])break;
            else ans=max(ans, 1+helper(i,d,arr,n,dp));
        }
        for(int i=ind-1;i>=max(0,ind-d) ;i--){
            if(arr[ind]<=arr[i])break;
            else ans=max(ans, 1+helper(i,d,arr,n,dp));
        }
        
        return dp[ind]=ans;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int answer=0;
        vector<int>dp(n+1,1);
        vector<vector<int>>sorted;
        for(int i=0;i<n;i++)sorted.push_back({arr[i],i});
        sort(sorted.begin(),sorted.end());
        for(auto &it:sorted){
            int ind=it[1];
            for(int i=ind+1;i<=(min(ind+d,n-1));i++){
                if(arr[ind]<=arr[i])break;
                else dp[ind]=max(dp[ind], 1+dp[i]);
            }
            for(int i=ind-1;i>=max(0,ind-d) ;i--){
                if(arr[ind]<=arr[i])break;
                else dp[ind]=max(dp[ind], 1+dp[i]);
            }
        }
        for(int i=0;i<n+1;i++){
            answer=max(answer,dp[i]);            
        }
        return answer;
    }
};
