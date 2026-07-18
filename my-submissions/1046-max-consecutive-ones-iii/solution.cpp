class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int safe=0,left=0,n=nums.size(),ans=INT_MIN;
        for(int right=0;right<n;right++){
            if(nums[right]==1||safe<k){
                int len=right-left+1;
                ans=max(ans,len);
                if(nums[right]==0)safe++;
            }else {
                while(safe>=k){
                    if(nums[left]==1){
                        left++;
                    }else{
                        safe--;
                        left++;
                    }
                }
                right--;
            }
        }
        return ans;
    }
};
