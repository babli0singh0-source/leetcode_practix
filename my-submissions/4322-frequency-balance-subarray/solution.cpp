class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int l = 0; l < n; l++) {
            unordered_map<int,int> freq;
            map<int,int> freqCnt;
            for (int r = l; r < n; r++) {
                int x = nums[r];
                int oldf = freq[x];
                if (oldf > 0) {
                    freqCnt[oldf]--;
                    if (freqCnt[oldf]==0)freqCnt.erase(oldf);
                }
                freq[x]++;
                freqCnt[oldf + 1]++;
                bool ok = false;
                if (freq.size() == 1)ok = true;
                else if (freqCnt.size() == 2) {
                    auto it = freqCnt.begin();
                    int a = it->first;
                    it++;
                    int b = it->first;
                    if (b == 2 * a)ok = true;
                }
                if (ok)ans = max(ans,r-l+1);
            }
        }
        return ans;
    }
};
