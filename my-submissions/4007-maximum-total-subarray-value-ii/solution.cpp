class Solution {
public:

    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> lg(n + 1);

        lg[1] = 0;

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int LOG = lg[n] + 1;

        vector<vector<int>> stMax(n, vector<int>(LOG));
        vector<vector<int>> stMin(n, vector<int>(LOG));

        for (int i = 0; i < n; i++) {
            stMax[i][0] = nums[i];
            stMin[i][0] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {

            for (int i = 0; i + (1 << j) <= n; i++) {

                stMax[i][j] =
                    max(
                        stMax[i][j - 1],
                        stMax[i + (1 << (j - 1))][j - 1]
                    );

                stMin[i][j] =
                    min(
                        stMin[i][j - 1],
                        stMin[i + (1 << (j - 1))][j - 1]
                    );
            }
        }

        auto queryMax = [&](int l, int r) {

            int len = r - l + 1;

            int p = lg[len];

            return max(
                stMax[l][p],
                stMax[r - (1 << p) + 1][p]
            );
        };

        auto queryMin = [&](int l, int r) {

            int len = r - l + 1;

            int p = lg[len];

            return min(
                stMin[l][p],
                stMin[r - (1 << p) + 1][p]
            );
        };

        auto value = [&](int l, int r) -> long long {

            return 1LL * queryMax(l, r)
                 - queryMin(l, r);
        };

        priority_queue<array<long long, 3>> pq;

        for (int l = 0; l < n; l++) {

            pq.push({
                value(l, n - 1),
                (long long)l,
                (long long)(n - 1)
            });
        }

        long long ans = 0;

        while (k--) {

            auto cur = pq.top();
            pq.pop();

            long long v = cur[0];
            int l = cur[1];
            int r = cur[2];

            ans += v;

            if (r > l) {

                pq.push({
                    value(l, r - 1),
                    (long long)l,
                    (long long)(r - 1)
                });
            }
        }

        return ans;
    }
};
