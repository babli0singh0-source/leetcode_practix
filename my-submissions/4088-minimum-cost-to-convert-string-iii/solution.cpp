class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        const long long INF = 1e18;
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            // Don't use any rule at this position
            if (source[i] == target[i] && dp[i + 1] != INF)
                dp[i] = dp[i + 1];

            // Try every rule
            for (int r = 0; r < rules.size(); r++) {

                string &pat = rules[r][0];
                string &rep = rules[r][1];

                int len = pat.size();

                if (i + len > n)
                    continue;

                bool ok = true;
                int wild = 0;

                // Pattern should match source
                for (int j = 0; j < len; j++) {
                    if (pat[j] == '*')
                        wild++;
                    else if (pat[j] != source[i + j]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok)
                    continue;

                // Replacement must equal target substring
                for (int j = 0; j < len; j++) {
                    if (rep[j] != target[i + j]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok)
                    continue;

                if (dp[i + len] != INF) {
                    dp[i] = min(dp[i],
                                dp[i + len] + costs[r] + wild);
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};

