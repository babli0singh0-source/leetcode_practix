class Solution {
    int lessthangoal(vector<int>& nums, int k){
        if(k<0)return 0;
        int n=nums.size();
        int ans=0;
        int odd=0,left=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2)odd++;
            while(odd>k){
                if(nums[left]%2)odd--;
                left++;
            }
            if(odd<=k)ans=ans+(i-left+1);
        }  
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessthangoal(nums,k)-lessthangoal(nums,k-1);
    }
};
