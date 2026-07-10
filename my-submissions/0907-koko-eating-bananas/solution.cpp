class Solution {
    long long divide(long long a,long long b){
        return (a+b-1)/b;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0;
        long long  maxi=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,1LL*piles[i]);
            sum+=piles[i];
        }
        long long mini=divide(sum,h);
        auto check=[&](long long mid)->bool{
            long long count=0;
            for(auto &it:piles){
                count+=divide(it,mid);
                if(count>h)return false;
            }
            return count<=h;
        };
        long long ans=maxi;
        while(mini<=maxi){
            long long mid=divide(maxi+mini,2);
            if(check(mid)){
                ans=min(ans,mid);
                maxi=mid-1;
            }else{
                mini=mid+1;
            }
        }
        return ans;
    }
};
