
class Solution {
public:
    static bool customsort(int a,int b){
        return a>b;
    }
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=nums[0],ans=0;
        for(int i=1;i<n;){
            while(i<n&&nums[i]==k){
                nums[i]=-10000;
                ans++;
                i++;
            }
            k=nums[i];
            i++;
        }
        sort(nums.begin(),nums.end(),customsort);
        reverse(nums.begin(),nums.begin()+n-ans);
        return n-ans;
        
    }
};
