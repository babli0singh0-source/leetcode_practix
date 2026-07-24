class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>allval;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                allval.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>nexval;
        for(auto &i:allval){
            for(auto &x:nums){
                nexval.insert(x^i);
            }
        }

        return nexval.size();
    }
};
