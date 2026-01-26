class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        vector<vector<int>>v;
        for(int i=1;i<arr.size();i++){
            int x=arr[i]-arr[i-1];
            if(x<ans){
                ans=x;
                v.clear();
                v.push_back({arr[i-1],arr[i]});
            }
            else if(ans==x){
                v.push_back({arr[i-1],arr[i]});
            }
        }
        return v;
    }
};
