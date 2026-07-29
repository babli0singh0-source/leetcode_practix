class Solution {
    string a1,a2,a3;
    int n1,n2,n3;
    bool helper(int i1,int i2,int i3,vector<vector<int>>&dp){
        if(i3==n3){
            return i1==n1&&i2==n2;
        }
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        bool case1=false;
        bool case2=false;
        if(i1<n1&& a1[i1]==a3[i3]){
            case1=helper(i1+1,i2,i3+1,dp);
        }
        if(i2<n2&& a2[i2]==a3[i3]){
            case2=helper(i1,i2+1,i3+1,dp);
        }
        return dp[i1][i2]=case1||case2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        a1=s1;  n1=s1.size();
        a2=s2;  n2=s2.size();
        a3=s3;  n3=s3.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        
        return helper(0,0,0,dp);
    }
};
