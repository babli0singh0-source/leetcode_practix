class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int left=0;
        int right=0;
        while(left<n&&right<n){
            if(nums[right]==val);
            else if(nums[left]==val){
                swap(nums[left],nums[right]);
                left++;
            }else if(nums[left]!=val&&nums[right]!=val){
                left++;
            }
            right++;
        }
        return left;
    }
};
