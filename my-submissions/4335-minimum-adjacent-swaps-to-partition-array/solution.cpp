// class Solution {
// public:
//     int minAdjacentSwaps(vector<int>& nums, int a, int b) {
//         long long mod=1e9+7;
//         int high=nums.size()-1;
//         long long ans=0;
//         set<pair<int,int>>lessa,moreb,between;
//         for(int i=0;i<=high;i++){
//             if(nums[i]<a)lessa.insert({nums[i],i});
//             else if(nums[i]>=a&&nums[i]<=b)between.insert({nums[i],i});
//             else if(nums[i]>b)moreb.insert({nums[i],i});
//         }
//         int low=0;
//         for(auto &it:lessa){
//             if(it.second==low){
//                 low++;
//                 continue;
//             }
//             int sc=(it.second-low)%mod;
//             ans=(ans+sc)%mod;
//             if(moreb.count({nums[low],low})){
//                 moreb.erase({nums[low],low});
//                 moreb.insert({nums[low],it.second});
//             }else if(between.count({nums[low],low})){
//                 between.erase({nums[low],low});
//                 between.insert({nums[low],it.second});
//             }
//             low++;
//         }
//         for(auto &it:between){
//             if(it.second==low){
//                 low++;
//                 continue;
//             }
//             int sc=(it.second-low)%mod;
//             ans=(ans+sc)%mod;
//             low++;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD = 1e9 + 7;

        long long ans = 0;

        long long cntMid = 0;
        long long cntHigh = 0;
        for (int x : nums) {
            if (x < a) {
                ans += cntMid + cntHigh;
            }
            else if (x <= b) {
                ans += cntHigh;
                cntMid++;
            }
            else {
                cntHigh++;
            }
        }

        return ans % MOD;
    }
};
