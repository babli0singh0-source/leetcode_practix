class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i])==0){
                if(nums[i]!=target[i]){
                    ans++;
                    mpp[nums[i]]++;
                }
            }else continue;
        }
        return ans;
        
    }
};
