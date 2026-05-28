class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for(auto &it:nums){
            ans=ans^it;
        }
        return ans;
        
    }
};
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int>mpp;
//         int ans =-1;
//         for(auto &it:nums){
//             mpp[it]++;
//             if(mpp[it]==2)mpp.erase(it);
//         }
//         return mpp.begin()->first;
        
//     }
// };
