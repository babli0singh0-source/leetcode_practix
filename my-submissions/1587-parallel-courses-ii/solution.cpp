class Solution {
public:
    int n, k;
    vector<int> pre;
    vector<int> dp;

    int solve(int mask) {
        // All courses completed
        if (mask == (1 << n) - 1)return 0;

        if (dp[mask] != -1)return dp[mask];
        int available = 0;

        // Find all courses that can be taken now
        for (int i = 0; i < n; i++) {
            // already completed
            if (mask & (1 << i))continue;

            // prerequisites satisfied
            if ((mask & pre[i]) == pre[i]) available |= (1 << i);

        }
        int ans = INT_MAX;
        // If <= k courses available, take all of them
        if (__builtin_popcount(available) <= k) {
            ans = 1 + solve(mask | available);
        }else {
            // Try every subset having exactly k courses
            for (int sub = available; sub; sub = (sub - 1) & available) {
                if (__builtin_popcount(sub) == k) {
                    ans = min(ans,1 + solve(mask | sub));
                }
            }
        }

        return dp[mask] = ans;
    }

    int minNumberOfSemesters(int N,vector<vector<int>>& relations,int K) {
        n = N;
        k = K;
        pre.assign(n, 0);
        // prerequisite bitmask
        for (auto &e : relations) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            pre[v] |= (1 << u);
        }
        dp.assign(1 << n, -1);
        return solve(0);
    }
};
