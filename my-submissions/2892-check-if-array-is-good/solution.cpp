class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        bool check=false;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=i+1){
                check=true;
                break;
            }
        }
        if(check)return false;
        if(nums[n-1]!=n-1)return false;
        return true;
    }
};
