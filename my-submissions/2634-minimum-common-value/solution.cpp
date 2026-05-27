class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j])return nums1[i];
            else if (nums1[i]>nums2[j])j++;
            else i++;
        }
        return -1;
    }
};
// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int>mpp;
//         for(auto &it:nums1){
//             mpp[it]++;
//         }
//         for(auto &it:nums2){
//             if(mpp.count(it))return it;
//         }
//         return -1;
//     }
// };

