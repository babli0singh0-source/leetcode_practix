class Solution {
public:
    

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        long long INF = 1e18;
        int n = source.size();
        int m = original.size();

        // Collect all strings
        unordered_map<string,int> id;
        vector<string> all;

        auto getId = [&](const string& s){
            if (!id.count(s)) {
                id[s] = all.size();
                all.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < m; i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int V = all.size();
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        for (int i = 0; i < V; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Group rules by length
        unordered_map<int, vector<int>> rulesByLen;
        for (int i = 0; i < m; i++)
            rulesByLen[original[i].size()].push_back(i);

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            // No operation
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            // Try all rule lengths
            for (auto &[len, rules] : rulesByLen) {
                if (i + len > n) continue;

                string srcSub = source.substr(i, len);
                string tgtSub = target.substr(i, len);

                if (!id.count(tgtSub)) continue;

                int tgtId = id[tgtSub];

                for (int k : rules) {
                    if (srcSub == original[k]) {
                        int u = id[original[k]];
                        if (dist[u][tgtId] < INF)
                            dp[i] = min(dp[i], dist[u][tgtId] + dp[i + len]);
                    }
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};

