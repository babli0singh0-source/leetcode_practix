class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for (int i=0,j=n-1;i<j;){
            if(nums[i]==0&&nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j--;
                count++;
            }
            else if(nums[j]==0&&nums[i]!=0){
                i++;
                j--;
            }else if(nums[j]==0&&nums[i]==0){
                j--;
            }else{
                i++;
            }
        }
        return count;
            
        
    }
};
