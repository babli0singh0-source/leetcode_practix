class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=1+prev[j-1];
                else{
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return n+m-(2*prev[m]);
    }
};
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n=word1.length();
//         int m=word2.length();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1]==word2[j-1]) dp[i][j]=1+dp[i-1][j-1];
//                 else{
//                     dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//                 }
//             }
//         }
//         return n+m-(2*dp[n][m]);
//     }
// };
