class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int l=0,r=nums.size()-1,ans=INT_MIN;
        sort(nums.begin(),nums.end());
        while(l<r){
            if((nums[l]+nums[r])>ans)ans=nums[l]+nums[r];
            l++;
            r--;
        }
        return ans;
        
    }
};
