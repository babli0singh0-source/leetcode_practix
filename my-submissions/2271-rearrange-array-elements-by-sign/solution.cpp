class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>posi(n,0);
        for(int i=0,j=0,k=1;i<n;i++){
            if(nums[i]>0){
                posi[j]=nums[i];
                j=j+2;
            }else{
                posi[k]=nums[i];
                k=k+2;
            }
        }
        return posi;
    }
};
