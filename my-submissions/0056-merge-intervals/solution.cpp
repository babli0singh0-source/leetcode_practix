class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        int s0=intervals[0][0];
        int s1=intervals[0][1];
        ans.push_back({s0,s1});
        for(int i=1;i<n;i++){
            if(s1<intervals[i][0]){
                s0=intervals[i][0];
                s1=intervals[i][1];
                ans.push_back({s0,s1});
            }else{
                ans.pop_back();
                s1=max(s1,intervals[i][1]);
                ans.push_back({s0,s1});
            }
        }
        return ans;
    }
};
