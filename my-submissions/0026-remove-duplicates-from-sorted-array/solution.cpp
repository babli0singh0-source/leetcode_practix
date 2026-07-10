class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last=nums.back();
        int n=nums.size();
        int left=0;
        int prev=nums[left];
        for(int right=1;right<n;){
            if(nums[right]<=prev){
                right++;
                continue;
            }
            left++;
            prev=nums[right];
            swap(nums[left],nums[right]);
            right++;
            if(nums[left]==last)break;
        }
        return left+1;
    }
};
