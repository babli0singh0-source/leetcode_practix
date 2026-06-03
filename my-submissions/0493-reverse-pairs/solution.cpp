class Solution {
    void finaldo(vector<int>& nums,int low,int mid,int high){
        vector<int>temp;
        int start=low;
        int right=mid+1;
        while(low<=mid&&right<=high){
            if(nums[low]<nums[right]){
                temp.push_back(nums[low]);
                low++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(low<=mid){
            temp.push_back(nums[low]);
            low++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=start;i<=high;i++){
            nums[i]=temp[i-start];
        }
    }
    int counting(vector<int>& nums,int low,int mid,int high){
        int right=mid+1;
        int c=0;
        for(int i=low;i<=mid;i++){
            while(right<=high&&(long long)nums[i]>(1LL*nums[right]*2))right++;
            c+=right-(mid+1);
        }
        return c;
    }
    int merge(vector<int>& nums,int low,int high){
        int mid=(low+high)/2;
        int c=0;
        if(low>=high)return c;
        c+=merge(nums,low,mid);
        c+=merge(nums,mid+1,high);
        c+=counting(nums,low,mid,high);
        finaldo(nums,low,mid,high);
        return c;
    }
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
    }
};
