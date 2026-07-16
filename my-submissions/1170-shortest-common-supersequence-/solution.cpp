class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(word1[i1-1]==word2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        int n=n1+n2-dp[n1][n2];
        string s(n,' ');
        int i=n-1;
        while(n1>0&&n2>0){
            if(word1[n1-1]==word2[n2-1]){
                s[i]=word1[n1-1];
                n1--;
                n2--;
                i--;
            }else if (dp[n1-1][n2]>dp[n1][n2-1]){
                s[i]=word1[n1-1];
                i--;
                n1--;
            }else{
                s[i]=word2[n2-1];
                i--;
                n2--;
            }
        }
        while (n1 > 0) {
            s[i] = word1[n1-1];
            i--;
            n1--;
        }
        while (n2 > 0) {
            s[i] = word2[n2-1];
            i--;
            n2--;
        }
        return s;
    }
};
