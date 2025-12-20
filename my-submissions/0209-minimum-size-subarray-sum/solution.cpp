class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,count=0,mini=INT_MAX,left=0;
        for(int i=0;i<nums.size();i++){
            count++;
            sum+=nums[i];
            while(sum>=target){
                mini=min(count,mini);
                sum-=nums[left];
                left++;
                count--;
            }
        }
        return mini==INT_MAX?0:mini;  
    }
};

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         queue<int>q;
//         int sum=0,count=0,mini=INT_MAX;
//         bool check=false;
//         for(int i=0;i<nums.size();i++){
//             q.push(nums[i]);
//             count++;
//             sum+=nums[i];
//             while(sum>=target){
//                 check=true;
//                 mini=min(count,mini);
//                 sum-=q.front();
//                 q.pop();
//                 count--;
//             }
//         }
//         if(!check)return 0;
//         return mini;  
//     }
// };
