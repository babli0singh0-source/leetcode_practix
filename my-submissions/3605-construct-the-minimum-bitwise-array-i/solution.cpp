class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            if (n == 2) {
                ans.push_back(-1);
            } else {
                // Find the first 0 bit from the right
                // We flip the last 1 in the trailing block of 1s
                for (int i = 1; i < 31; ++i) {
                    if (((n >> i) & 1) == 0) {
                        // Found the first zero at position i
                        // The answer is n with the (i-1)-th bit flipped to 0
                        ans.push_back(n ^ (1 << (i - 1)));
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
};
