// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid, int k) {
        
//     }
// };
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;
        
        // dp[p][i][j] is the min cost to reach (i, j) with p teleports
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m, vector<int>(n, INF)));

        // Base case: starting point (0,0) has 0 cost
        for (int p = 0; p <= k; ++p) {
            dp[p][0][0] = 0;
        }

        for (int p = 0; p <= k; ++p) {
            // If p > 0, we can reach (i, j) via teleportation from any (x, y) 
            // in dp[p-1] where grid[x][y] >= grid[i][j].
            if (p > 0) {
                // To do this efficiently, collect all (cost, grid_value) from dp[p-1]
                vector<pair<int, int>> reachable;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dp[p-1][i][j] != INF) {
                            reachable.push_back({grid[i][j], dp[p-1][i][j]});
                        }
                    }
                }
                // Sort by grid value descending to easily find min cost for grid[x][y] >= grid[i][j]
                sort(reachable.rbegin(), reachable.rend());
                
                // Precompute suffix minimums of costs
                // min_cost_at_least_val[v] = min cost to reach any cell with grid value >= v
                // Since grid values are up to 10^4, we can use a simple array or a monotonic update
                vector<int> min_cost_for_val(10001, INF);
                int current_min = INF;
                int idx = 0;
                for (int v = 10000; v >= 0; --v) {
                    while (idx < reachable.size() && reachable[idx].first >= v) {
                        current_min = min(current_min, reachable[idx].second);
                        idx++;
                    }
                    min_cost_for_val[v] = current_min;
                }

                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        dp[p][i][j] = min(dp[p][i][j], min_cost_for_val[grid[i][j]]);
                    }
                }
            }

            // Normal moves (Down and Right) within the same teleport layer p
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0 && dp[p][i-1][j] != INF) {
                        dp[p][i][j] = min(dp[p][i][j], dp[p][i-1][j] + grid[i][j]);
                    }
                    if (j > 0 && dp[p][i][j-1] != INF) {
                        dp[p][i][j] = min(dp[p][i][j], dp[p][i][j-1] + grid[i][j]);
                    }
                }
            }
        }

        int ans = INF;
        for (int p = 0; p <= k; ++p) {
            ans = min(ans, dp[p][m-1][n-1]);
        }
        return ans;
    }
};
