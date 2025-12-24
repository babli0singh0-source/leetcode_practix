class Solution {
public:
    int search(int x,vector<int>&copy){
        for(int i=0;i<copy.size();i++){
            if(copy[i]==x)return i;
        }
        return -1;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>copy(nums.begin(),nums.end());
        sort(copy.begin(),copy.end());
        for(int i=0;i<nums.size();i++){
            nums[i]=search(nums[i],copy);
        }
        return nums;    
    }
};
    // int bs(int x,vector<int>&copy){
    //     int l=0,h=copy.size()-1;int mid=-1;
    //     while(l<h){
    //         mid=(l+h)/2;
    //         if(copy[mid]==x)break;
    //         else if(x>copy[mid])l=mid+1;
    //         else h=mid-1;
    //     }
    //     return mid;
    // }
