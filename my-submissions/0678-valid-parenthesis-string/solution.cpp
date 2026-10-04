class Solution {
    int n;
    string word;
    bool helper(int valid, int curr,vector<vector<int>>&dp){
        if(valid < 0) return false;
        if(curr>=n)return valid==0;
        if(dp[valid][curr]!=-1)return dp[valid][curr];
        if(word[curr]=='*'){
            return dp[valid][curr]=helper(valid+1,curr+1,dp)||helper(valid-1,curr+1,dp)||helper(valid,curr+1,dp);
        }else if(word[curr]=='('){
            return dp[valid][curr]= helper(valid+1,curr+1,dp);
        }else{
            return dp[valid][curr]=helper(valid-1,curr+1,dp);
        }
    }
public:
    bool checkValidString(string s) {
        n=s.size();
        word=s;
        vector<vector<int>>dp(n,vector<int>(n + 1, -1));
        return helper(0,0,dp);
    }
};

