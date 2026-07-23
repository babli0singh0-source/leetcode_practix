class Solution {
    int helper(int i, int amount, vector<int>& coins,vector<vector<int>>& dp) {
        if (amount == 0) return 0;

        if (i == coins.size()) return 1e9;

        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = helper(i + 1, amount, coins, dp);

        int take = 1e9;
        if (coins[i] <= amount) take = 1 + helper(i, amount - coins[i], coins, dp);

        return dp[i][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(0, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};
