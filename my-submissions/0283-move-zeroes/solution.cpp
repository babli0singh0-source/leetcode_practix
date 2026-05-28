class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0,temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                temp=nums[i];
                nums[i]=nums[c];
                nums[c]=temp;
                c++;
            }
        }
        return;
        
    }
};
