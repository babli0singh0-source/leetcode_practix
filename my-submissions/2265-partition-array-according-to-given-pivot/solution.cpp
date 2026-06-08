class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // int left=0;
        // int n=nums.size();
        // int right=n-1;
        // int mid=(left+n-1)/2;
        // int right=mid+1;
        // cout<<mid;
        queue<int>small;
        queue<int>big;
        int count=0;
        for(auto &it:nums){
            if(it<pivot)small.push(it);
            else if(it==pivot)count++;
            else big.push(it);
        }
        int i=0;
        while(!small.empty()){
            nums[i]=small.front();
            small.pop();
            i++;
        }
        while(count>0){
            nums[i]=pivot;
            i++;
            count--;
        }
        while(!big.empty()){
            nums[i]=big.front();
            big.pop();
            i++;
        }
        // while(mid<=right&&right<n){
        //     if(nums[left]<pivot){
        //         left++;
        //         mid++;
        //     }else if(nums[left]==pivot){
        //         swap(nums[left],nums[mid]);
        //         mid++;
        //     }else{
        //         swap(nums[left],nums[right]);
        //         right++;
        //     }
        // }
        return nums;
    }
};
