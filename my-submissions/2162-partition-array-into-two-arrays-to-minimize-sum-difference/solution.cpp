class Solution { 
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        long long total=0;
        for(int &i:nums)total+=i;
        int m=n/2;
        vector<vector<long long>> left(m + 1), right(m + 1);
        for (int mask = 0; mask < (1 << m); mask++) {
            long long suml = 0,sumr=0;
            int bits = 0;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    suml += nums[i];//left
                    sumr +=nums[m+i];//right
                }
            }
            left[bits].push_back(suml);
            right[bits].push_back(sumr);
        }
        for (int i = 0; i <= m; i++)sort(right[i].begin(), right[i].end());
        long long ans = LLONG_MAX;
        for (int k = 0; k <= m; k++) {
            for (long long sumL : left[k]) {
                long long target = total / 2 - sumL;
                auto &vec = right[m - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end()) {
                    ans = min(ans,llabs(total - 2 * (sumL + *it)));
                }
                if (it != vec.begin()) {
                    --it;
                    ans = min(ans,llabs(total - 2 * (sumL + *it)));
                }
            }
        }
        return (int)ans;
    }
};
