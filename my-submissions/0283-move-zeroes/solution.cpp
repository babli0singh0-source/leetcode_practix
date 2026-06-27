class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(left!=-1){
                    swap(nums[i],nums[left]);
                    left++;
                }
            }else{
                if(left==-1)left=i;
            }
        }
    }
};
