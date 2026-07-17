class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<int>ans;
        int n=nums.size();
        int maxi=-1;
        for(int &i:nums)maxi=max(i,maxi);
        vector<int>freq(maxi+1,0);
        for(int &i:nums)freq[i]++;
        vector<int>count(maxi+1,0);
        for(int i=1;i<=maxi;i++){
            for(int d=i;d<=maxi;d+=i){
                count[i]+=freq[d];
            }
        }
        vector<long long> exact(maxi + 1);
        for (int d = maxi; d >= 1; d--) {
            exact[d] = 1LL*count[d]*(count[d]-1)/2;
            for (int multiple = 2 * d; multiple <= maxi; multiple += d){
                exact[d] -= exact[multiple];
            }
        }
        vector<long long>cumu(maxi+1,0);
        for(int i=1;i<=maxi;i++){
            cumu[i]=cumu[i-1]+exact[i];
        }
        for(auto &it:queries){
            auto i=upper_bound(cumu.begin(),cumu.end(),it);
            int k=i-cumu.begin();
            ans.push_back(k);
        }
        return ans;
    }
};
