class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, count=0,ans=-1;
        while(i<nums.size()){
            while(i<nums.size()&&nums[i]==1){
                count++;
                i++;
            }
            ans=max(ans,count);
            count=0;
            i++;
        }
        return ans;
        
    }
};
