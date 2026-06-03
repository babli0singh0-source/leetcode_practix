class Solution {
    static bool custumsort(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0])return a[0]>b[0];
        return a[1]>b[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),custumsort);
        int i=intervals.size();
        vector<vector<int>>ans;
        int s=intervals[i-1][0];
        int e=intervals[i-1][1];
        i=i-2;
        while(i>=0){
            if(e>=intervals[i][0]){
                e=max(e,intervals[i][1]);
            }else{
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
            i--;
        }
        ans.push_back({s,e});
        return ans;
    }
};
