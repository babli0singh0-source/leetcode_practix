class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long lsum=0;
        long long sqsum=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                lsum+=grid[i][j];
                sqsum+=1LL*grid[i][j]*grid[i][j];
            }
        }
        int diff=(1LL*(n*n)*(n*n+1))/2 - lsum;
        int sum=((1LL*(n*n)*(n*n+1)*(2*n*n +1))/6-sqsum)/diff;
        return {(sum-diff)/2,(sum+diff)/2};
    }
};
