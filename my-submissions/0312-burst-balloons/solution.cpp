class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for (int x : nums) arr.push_back(x);
        arr.push_back(1);
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=2;i<n;i++){//curr
            for(int j=0;j<n-i;j++){//left
                int next=i+j;//right
                for(int k=j+1;k<next;k++){
                    dp[j][next]=max(dp[j][next],dp[j][k]+dp[k][next]+arr[next]*arr[k]*arr[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
