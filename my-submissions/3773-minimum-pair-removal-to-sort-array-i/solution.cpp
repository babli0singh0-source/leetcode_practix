// class Solution {
// public:
//     int minimumPairRemoval(vector<int>& nums) {
//         int val=INT_MAX;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         queue<int>q;
//         vector<int>pos;
//         while(check){
//             for(int i=0;i<nums.size()-1;i++){
//                 if(nums[i]<nums[i+1])check=false;
//                 if((nums[i]+nums[i+1])<val){
//                     q.pop();
//                     q.push(i);
//                 }else if((nums[i]+nums[i+1])=val){
//                     q.push(i);
//                 }
//             }
//             if(!check){
//                 nums.erase(nums.begin()+)
//             }

//         }
        
        
//     }
// };
class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            // Find leftmost adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // Merge the pair
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ops++;
        }

        return ops;
    }
};

