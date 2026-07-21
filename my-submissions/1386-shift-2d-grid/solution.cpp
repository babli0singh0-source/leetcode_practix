class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        k=k%(n*m);
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                int node=(i*n+j);
                int newnode=(node+k)%(n*m);
                int r=newnode/n;
                int c=newnode%n;
                ans[r][c]=grid[i][j];
            }
        }
        return ans;
    }
};
