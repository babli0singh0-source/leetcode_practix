class Solution {
    int helper(vector<int>& nums, int k){
        unordered_map<int,int>mpp;
        int n=nums.size();
        int ans=0;
        int left=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            bool check=false;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
            ans+=i-left+1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};
