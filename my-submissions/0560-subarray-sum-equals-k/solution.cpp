class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int presum=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int rem=presum-k;
            c+=mpp[rem];
            mpp[presum]+=1;
        }
        return c;
    }
};
