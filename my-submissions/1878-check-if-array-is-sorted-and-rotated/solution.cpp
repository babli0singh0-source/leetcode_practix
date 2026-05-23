class Solution {
public:
    bool check(vector<int>& nums) {
        int cc=0;
        bool ch=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                ch=false;
                cc++;
            }
            if(!ch){
               if(nums[i+1]>nums[0])return false;
            }
            if(cc>1)return false;
        }
        return true;
        
    }
};
