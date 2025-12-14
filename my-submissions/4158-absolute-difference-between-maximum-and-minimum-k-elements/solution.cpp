class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        if(nums.size()<=k)return 0;
        sort(nums.begin(),nums.end());
        int small=0,large=0;
        for(int i=0;i<k;i++){
            small=small+nums[i];
            large = large+nums[nums.size()-i-1];   
        }
        return large-small;
        
    }
};
