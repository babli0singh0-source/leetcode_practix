class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k==0)return;
        vector<int>rem(k);
        for(int i=0;i<k;i++){
            rem[k-i-1]=(nums[nums.size()-1]);
            nums.pop_back();
        }
        nums.insert(nums.begin(),rem.begin(),rem.end());
        return ;
        
    }
};
