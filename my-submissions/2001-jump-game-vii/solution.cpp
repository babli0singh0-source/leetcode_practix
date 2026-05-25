class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        queue<int>q;
        q.push(0);
        int limit=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            int start=max(i + minJump,limit);
            int end=min(i + maxJump, n - 1);
            for(int j=start;j<=end;j++){
                if(s[j]=='0'){
                    if(j==n-1)return true;
                    q.push(j);
                }
            }
            limit=end+1;
        }
        return false ;
    }
};

// class Solution {
//     int helper(int i,int n,string &s,int minJump,int maxJump,vector<int>&zero,vector<int>&dp){
//         if(i==n-1)return true;
//         if(dp[i]!=-1)return dp[i];
//         for(auto &it:zero){
//             if(i + minJump <= it&& it <= min(i + maxJump, n - 1)){
//                 if(helper(it,n,s,minJump,maxJump,zero,dp))return dp[i]=true;
//             }
//         }
//         return dp[i]=false; 
//     }
// public:
//     bool canReach(string s, int minJump, int maxJump) {
//         int n=s.length();
//         vector<int>zero;
//         for(int i=1;i<n;i++){
//             if(s[i]=='0')zero.push_back(i);
//         }  
//         vector<int>dp(n+1,-1);
//         return helper(0,n,s,minJump,maxJump,zero,dp);      
//     }
// };
