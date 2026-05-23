class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>even(k,0);
        vector<int>odd(k,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem=((nums[i]%k)+k)%k;
            for(int j=0;j<k;j++){
                int f=(j-rem+k)%k;
                int b=(rem-j+k)%k;
                int cost= min(f,b);
                if(i%2==0)even[j]+=cost;
                else odd[j]+=cost;
            }
        }
        int ans=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y)continue;
                ans=min(ans,even[x]+odd[y]);
            }
        }
        return ans;  
    }
};
