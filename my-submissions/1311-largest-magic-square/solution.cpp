// class Solution {
// public:
//     int largestMagicSquare(vector<vector<int>>& grid) {
//         int n=grid.size(),m=grid[0].size();
//         vector<vector<int>>sumrow(n,vector<int>(m));
//         vector<vector<int>>sumcol(n,vector<int>(m));
//         for(int i=0;i<n;i++){
//             sumrow[i][0]=grid[i][0];
//             for(int j=1;j<m;j++){
//                 sumrow[i][j]=sumrow[i][j-1]+grid[i][j];
//             }
//         }
                        
//         for(int j=0;j<m;j++){
//             sumcol[0][j]=grid[0][j];
//             for(int i=1;i<n;i++){
//                 sumcol[i][j]=sumcol[i-1][j]+grid[i][j];
//             }
//         }
//         for(int side=min(n,m);side>1;side--){
//             for(int i=0;i+side-1<n;i++){
//                 for(int j=0;j+side-1<m;j++){
//                     int target=sumrow[i][j+side-1]-(j>0?sumrow[i][j-1]:0);
//                     bool check=true;
//                     //rows
//                     for(int r=i+1;r<i+side;r++){
//                         int sum=sumrow[r][j+side-1]-(j>0?sumrow[r][j-1]:0);
//                         if(target!=sum){
//                             check=false;
//                             break;
//                         }
//                     }
//                     if(!check)continue;
//                     //columns
//                     for(int c=j+1;c<j+side;j++){
//                         int sum=sumcol[i+side-1][c]-(i>0?sumrow[i-1][c]:0);
//                         if(target!=sum){
//                             check=false;
//                             break;
//                         }
//                     }
//                     if(!check)continue;
//                     //diagonal
//                     int dia=0,anti=0;
//                     for(int k=0;k<side;k++){
//                         dia+=grid[i+k][j+k];
//                         anti+=grid[i+k][j+side-1-k];
//                     }
//                     if(dia==target&&anti==target)return side;

//                 }
//             }

//         }
//         return 1;    
//     }
// };
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Row wise Prefix Sum
        vector<vector<int>> rowCumsum(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            rowCumsum[i][0] = grid[i][0];
            for (int j = 1; j < cols; ++j) {
                rowCumsum[i][j] = rowCumsum[i][j - 1] + grid[i][j];
            }
        }

        // Column wise Prefix Sum
        vector<vector<int>> colCumsum(rows, vector<int>(cols));
        for (int j = 0; j < cols; ++j) {
            colCumsum[0][j] = grid[0][j];
            for (int i = 1; i < rows; ++i) {
                colCumsum[i][j] = colCumsum[i - 1][j] + grid[i][j];
            }
        }
        for (int side = min(rows, cols); side >= 2; side--) {
            for (int i = 0; i + side - 1 < rows; ++i) {
                for (int j = 0; j + side - 1 < cols; ++j) {

                    int targetSum = rowCumsum[i][j + side - 1] - (j > 0 ? rowCumsum[i][j - 1] : 0);

                    bool allSame = true;

                    // Check rows
                    for (int r = i + 1; r < i + side; ++r) {
                        int rowSum = rowCumsum[r][j + side - 1] - (j > 0 ? rowCumsum[r][j - 1] : 0);
                        if (rowSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) 
                        continue;

                    // Check columns
                    for (int c = j; c < j + side; ++c) {
                        int colSum = colCumsum[i + side - 1][c] - (i > 0 ? colCumsum[i - 1][c] : 0);
                        if (colSum != targetSum) {
                            allSame = false;
                            break;
                        }
                    }
                    if (!allSame) 
                        continue;

                    // Check diagonals
                    int diag     = 0;
                    int antiDiag = 0;
                    for (int k = 0; k < side; ++k) {
                        diag += grid[i + k][j + k];
                        antiDiag += grid[i + k][j + side - 1 - k];
                    }

                    if (diag == targetSum && antiDiag == targetSum) {
                        return side;
                    }
                }
            }
        }

        return 1;
    }
};

