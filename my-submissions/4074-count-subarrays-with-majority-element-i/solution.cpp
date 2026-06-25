class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count =0;
        for(int &i:nums){
            if(i==target)count++;
        }
        int ans=0;
        int notarget=count;
        for(int i=0;i<nums.size();i++){
            int temp=notarget;
            for(int j=nums.size()-1;j>=i;j--){
                int s=j-i+1;
                if(temp>s/2)ans++;
                if(nums[j]==target){
                    temp--;
                }
            }
            if(nums[i]==target)notarget--;
        }
        return ans;
    }
};
