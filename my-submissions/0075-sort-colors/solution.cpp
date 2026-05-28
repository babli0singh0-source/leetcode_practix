class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high =nums.size()-1,low=0,mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         vector<int>nn(3,0);
//         for(auto &it:nums){
//             nn[it]++;
//         }
//         int i=0;
//         while(nn[0]>0){
//             nums[i]=0;
//             nn[0]--;
//             i++;
//         }
//         while(nn[1]>0){
//             nums[i]=1;
//             nn[1]--;
//             i++;
//         }
//         while(nn[2]>0){
//             nums[i]=2;
//             nn[2]--;
//             i++;
//         }
//     }
// };
//this is better solution as it involves a vector of 3 size ie sc is O(3)and tc of O(N)+O(N)
//can we do better?
//the dutch national flag algorithm here on top
//we can do any sorting algos but those will take O(N2) or best one O(Nlog N)
//but we will do O(n)
