class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long long curr=0;
        for(int i=0;i<nums.size();i++){
            long long target = nums[i];
            curr+=target;
            if((i-left+1)*target-curr>k){
                curr-=nums[left];
                left++;
            }
        }
        return nums.size()-left;
    }
};
