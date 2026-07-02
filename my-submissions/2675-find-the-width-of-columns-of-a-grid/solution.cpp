class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>result;
        for(int i=0;i<m;i++){
            int ans=INT_MIN;
            for(int j=0;j<n;j++){
                string temp=to_string(abs(grid[j][i]));
                int s=temp.size();
                if(grid[j][i]<0)ans=max(ans,s+1);
                else ans=max(ans,s);
            }
            result.push_back(ans);
        }
        return result;
    }
};
