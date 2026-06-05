class Solution {
    struct Node {
        long long ways;
        long long waviness;
    };
    Node dp[17][11][11][2][2];
    bool vis[17][11][11][2][2];
    Node helper(string &s, int prev2, int prev1,int curr, bool tight, bool lz) {
        if (curr == s.size()) {
            return {1, 0};
        }
        if (vis[curr][prev2][prev1][tight][lz])return dp[curr][prev2][prev1][tight][lz];
        vis[curr][prev2][prev1][tight][lz] = true;
        Node ans = {0, 0};
        int limit = tight ? (s[curr] - '0') : 9;
        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            if (lz && d == 0) {
                Node child = helper(s,10,10,curr+1,newTight,true);
                ans.ways += child.ways;
                ans.waviness += child.waviness;
            }else {
                int newPrev2, newPrev1;
                if (lz) {
                    newPrev2 = 10;
                    newPrev1 = d;
                }else {
                    newPrev2 = prev1;
                    newPrev1 = d;
                }
                int extra = 0;
                if (!lz && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        extra = 1;
                    }
                }
                Node child = helper(s,newPrev2,newPrev1,curr + 1,newTight,false);
                ans.ways += child.ways;
                ans.waviness += child.waviness +1LL * extra * child.ways;
            }
        }
        return dp[curr][prev2][prev1][tight][lz] = ans;
    }
    long long solve(long long x) {
        if (x < 0) return 0;
        string s = to_string(x);
        memset(vis, 0, sizeof(vis));
        Node ans = helper(s, 10, 10, 0, true, true);
        return ans.waviness;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
