class Solution {
public:
    int addDigits(int nums) {
        if(nums==0)return nums;
        return nums%9==0?9:nums%9;
    }
};
