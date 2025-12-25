class Solution {
public:
    long long count(vector<int>&candies,int k){
        long long ans=0;
        for(auto &it:candies){
            if(it/k>0)ans+=it/k;
        }return ans;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1,h=*max_element(candies.begin(),candies.end()),mid=0,ans=0;
        while(l<=h){
            mid=(l+h)/2;
            long long iter=count(candies,mid);
            if(iter>=k){
                l=mid+1;
                ans=mid;
            }
            else h=mid-1;
        } 
        return ans;
    }
};
