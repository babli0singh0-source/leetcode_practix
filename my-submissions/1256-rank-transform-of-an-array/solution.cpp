class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>copy;
        for(int i=0;i<n;i++){
            copy.push_back({arr[i],i});
        }
        sort(copy.begin(),copy.end());
        int rank=1;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[copy[i].second]=rank;
            if(i+1<n&&copy[i+1].first==copy[i].first)continue;
            rank++;
        }
        return ans;
    }
};
