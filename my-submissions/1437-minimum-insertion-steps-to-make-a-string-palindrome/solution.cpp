class Solution {
    // int helper(int i1,int i2,string s1,string s2,vector<vector<int>>&dp){
    //     if(i1<0||i2<0)return 0;
    //     if(dp[i1][i2]!=-1)return dp[i1][i2];
    //     if(s1[i1]==s2[i2])return dp[i1][i2]=1+helper(i1-1,i2-1,s1,s2,dp);
    //     else{
    //         return dp[i1][i2]= max(helper(i1-1,i2,s1,s2,dp),helper(i1,i2-1,s1,s2,dp));
    //     }
    // }
public:
    int minInsertions(string s) {
        int n=s.length();
        string s1=s;
        reverse(s.begin(),s.end());
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        //vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                if(s1[i1-1]==s[i2-1]) curr[i2]=1+prev[i2-1];
                else{
                    curr[i2]= max(prev[i2],curr[i2-1]);
                }
            }
            prev=curr;
        }
        return n-prev[n];
    }
};
