class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007;
        unordered_map<int, int> leftCount, rightCount;
        for (int x : nums) rightCount[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            rightCount[nums[j]]--;
            long long a = nums[j] * 2;
            if (leftCount.count(a) && rightCount.count(a))
                ans = (ans + (long long)leftCount[a] * rightCount[a]) % MOD;
            leftCount[nums[j]]++;
        }
        return ans % MOD;
    }
};
// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         unordered_map<int,vector<int>>mpp;

//         int count=0,zeroc=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0)zeroc++;
//             int val=nums[i]/2;
//             if(mpp.find(nums[i])!=mpp.end()){
//                 if(mpp.find(val)!=mpp.end()){
//                     vector<int>i1=mpp[nums[i]];
//                     vector<int>i2=mpp[val];
//                     for(int j=0;j<i1.size();j++){
//                         for(int k=0;k<i2.size();k++){
//                             if(i2[k]>i1[j]&&i2[k]<i)count++;
//                             else i2.erase(i2.begin() +k+1);
//                         }
//                     }
//                 }
//                 mpp[nums[i]].push_back(i);
//             }else {
//                 mpp[nums[i]]={i};
//             }
//         }
//         int mod=1e9;
//         if(zeroc>2)return ((((zeroc)*(zeroc-1)*(zeroc-2))/6)+count)%mod ;
//         return count%mod;    
//     }
// };
// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         unordered_map<int,pair<int,int>>mpp;

//         int count=0,zeroc=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0)zeroc++;
//             int val=nums[i]/2;
//             if(mpp.find(nums[i])!=mpp.end()){
//                 int k=mpp[nums[i]].second;
//                 if(mpp.find(val)!=mpp.end()){
//                     int i1=mpp[nums[i]].first;
                    
//                     int i2=mpp[val].first;
//                     int mult=mpp[val].second;
//                     if(i2>i1&&i2<i){
//                         count=count+mult*k;
//                         cout<<nums[i]<<' '<<i1<<' '<<k<<' '<<i2<<' '<<mult<< ' '<<i<<endl;  
//                     }
//                 }
//                     mpp[nums[i]]={i,k+1};
//             }else {
//                 mpp[nums[i]]={i,1};
//             }
//         }
//         int mod=1e9;
//         if(zeroc>2)return ((((zeroc)*(zeroc-1)*(zeroc-2))/6)+count)%mod ;
//         return count%mod;    
//     }
// };
