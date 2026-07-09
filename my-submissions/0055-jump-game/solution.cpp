class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int temp=nums[0];
        for(int i=1;i<n;i++){
            if(temp==0)return false;
            temp--;
            temp=max(temp,nums[i]);
        }
        return true;
    }
};
