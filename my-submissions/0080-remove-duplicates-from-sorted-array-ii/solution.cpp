class Solution {
public:
    static bool customsort(int a,int b){
        return a>b;
    }
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=nums[0],ans=0;
        for(int i=1;i<n;){
            int count=1;
            while(i<n&&nums[i]==k){
                count++;
                if(count>2){
                    nums[i]=-1000000;
                    ans++;
                }
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
