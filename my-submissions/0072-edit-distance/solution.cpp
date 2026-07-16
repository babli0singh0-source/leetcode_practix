class Solution {
    int helper(int i1,int i2,string &word1, string &word2,vector<vector<int>>&dp){
        if(i1<0)return i2+1;
        if(i2<0)return i1+1;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(word1[i1]==word2[i2])return dp[i1][i2]=0+helper(i1-1,i2-1,word1,word2,dp);
        int insert=1+helper(i1,i2-1,word1,word2,dp);
        int replace=1+helper(i1-1,i2-1,word1,word2,dp);
        int del=1+helper(i1-1,i2,word1,word2,dp);
        return dp[i1][i2]=min({insert,replace,del});
    }
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(n1-1,n2-1,word1,word2,dp);
    }
};
