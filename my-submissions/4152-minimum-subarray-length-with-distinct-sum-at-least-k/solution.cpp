class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0,ans=INT_MAX,l=0;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==0){
                sum+=nums[i];
            }
            mpp[nums[i]]++;
            while(sum>=k){
                ans=min(ans,i-l+1);
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)sum-=nums[l];
                l++;
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};
