class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            //if(nums[i]>target)return {};
            int diff=target-nums[i];
            if(mpp.count(diff)){
                return {mpp[diff],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
