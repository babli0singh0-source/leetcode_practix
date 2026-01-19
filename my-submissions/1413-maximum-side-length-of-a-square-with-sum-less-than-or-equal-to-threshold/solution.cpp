// class Solution {
// public:
//     int maxSideLength(vector<vector<int>>& mat, int threshold) {
//         int n=mat.size(),m=mat[0].size(),ans=0;
//         vector<vector<long long>>presum(n+1,vector<long long>(m+1,0));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(mat[i-1][j-1]<=threshold)ans=1;
//                 presum[i][j]=mat[i-1][j-1]-presum[i-1][j-1]+presum[i-1][j]+presum[i][j-1];
//             }
//         }
//         for(int side=min(n,m);side>1;side--){
//             for(int i=0;i+side-1<n;i++){
//                 for(int j=0;j+side-1<m;j++){
//                     long long sum=presum[i+side][j+side]+presum[i][j]-presum[i+side][j]-presum[i][j+side];
//                     if(sum<=threshold)return side;
//                 }
//             }
//         }
//         return ans;  
//     }
// };
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size(),ans=0;
        vector<vector<long long>>presum(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1]<=threshold)ans=1;
                presum[i][j]=mat[i-1][j-1]-presum[i-1][j-1]+presum[i-1][j]+presum[i][j-1];
            }
        }
        for(int side=min(n,m);side>1;side--){
            for(int i=n-side;i>=0;i--){
                for(int j=m-side;j>=0;j--){
                    long long sum=presum[i+side][j+side]+presum[i][j]-presum[i+side][j]-presum[i][j+side];
                    if(sum<=threshold)return side;
                }
            }
        }
        return ans;  
    }
};

