class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int sr=intervals[0][0];
        int sc=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=sc&&intervals[i][1]<=sc){
                continue;
            }else if(intervals[i][0]<=sr&&intervals[i][1]>=sc){
                sr=intervals[i][0];
                sc=intervals[i][1];
            }else {
                sr=intervals[i][0];
                sc=intervals[i][1];
                ans++;
            }
        }
        return ans+1;
    }
};
