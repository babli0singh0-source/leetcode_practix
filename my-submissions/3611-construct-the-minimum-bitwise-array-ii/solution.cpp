// class Solution {
// public:
//     vector<int> minBitwiseArray(vector<int>& nums) {
        
//     }
// };
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 2) {
                ans[i] = -1;
            } else {
                // Find the first 0 bit from the right to identify 
                // the end of the trailing ones block.
                for (int bit = 0; bit < 31; ++bit) {
                    // Check if the bit at (bit + 1) is a 0
                    if (!((nums[i] >> (bit + 1)) & 1)) {
                        // Flip the bit at 'bit' position from 1 to 0
                        ans[i] = nums[i] ^ (1 << bit);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
