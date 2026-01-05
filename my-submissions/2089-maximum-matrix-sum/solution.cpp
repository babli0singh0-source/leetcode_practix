class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                sum += abs(x);
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negCount % 2 == 1)
            sum -= 2LL * minAbs;

        return sum;
    }
};
// class Solution {
// public:
//     long long maxMatrixSum(vector<vector<int>>& matrix) {
//         int ans=INT_MIN,n=matrix.size(),total=0;
//         vector<vector<int>>vis(n,vector<int>(n,0));
//         int dr[]={0,1,0,-1};
//         int dc[]={1,0,-1,0};
//         queue<pair<int,int>>q;
//         q.push({0,0});
//         vis[0][0]=1;
//         total+=matrix[0][0];
//         map<pair<pair<int,int>, pair<int,int>>, int> mpp;;
//         while(q.size()!=0){
//             int r=q.front().first;
//             int c=q.front().second;
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nr=r+dr[i];
//                 int nc=c+dc[i];
//                 if(nr>=0&&nc>=0&&nr<n&&nc<n){
//                     if(!vis[nr][nc])total+=matrix[nr][nc];
//                     if(mpp.count({{r,c},{nr,nc}})==0||mpp.count({{nr,nc},{r,c}})==0){
//                         int sum=matrix[r][c]*-1 +matrix[nr][nc]*-1;
//                         ans=max(ans,sum);
//                         mpp[{{r,c},{nr,nc}}]++;

//                     }
//                     vis[nr][nc]=1;
//                     q.push({nr,nc});
//                 }
//             }
//         }
//         total =total+2*ans;
//         return total;   
//     }
// };
