class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long prod=1;
        int ans=0;
        int left=0;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            while(prod>=k&&left<n){
                prod=prod/nums[left];
                left++;
            }
            if(prod<k){
                ans+=1+(i-left);
            }
        }
        return ans;
    }
};
