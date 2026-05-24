class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;){
            int count=1;
            ans.push_back(nums[i]);
            while(i+1<n&&nums[i]==nums[i+1]){
                count++;
                if(count<(k+1))ans.push_back(nums[i+1]);
                i++;
            }
            i++;
        }
        return ans;
        
    }
};
