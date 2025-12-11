class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> minY, maxY;
        unordered_map<int, int> minX, maxX;

        // initialize with extreme values
        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            if (!minY.count(x)) {
                minY[x] = maxY[x] = y;
            } else {
                minY[x] = min(minY[x], y);
                maxY[x] = max(maxY[x], y);
            }

            if (!minX.count(y)) {
                minX[y] = maxX[y] = x;
            } else {
                minX[y] = min(minX[y], x);
                maxX[y] = max(maxX[y], x);
            }
        }

        int covered = 0;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            bool left  = (minY[x] < y);
            bool right = (maxY[x] > y);

            bool up    = (minX[y] < x);
            bool down  = (maxX[y] > x);

            if (left && right && up && down)
                covered++;
        }

        return covered;
    }
};




//         unordered_map<int,vector<int>>row,col;
//         for(auto &it:buildings){
//             row[it[0]].push_back(it[1]);
//             col[it[1]].push_back(it[0]);
//         }
//         for(auto &it:row)sort(it.second.begin(),it.second.end());
//         for(auto &it:col)sort(it.second.begin(),it.second.end());
//         int count=0;
//         for(auto &p :buildings){
//             int a=p[0],b=p[1];
//             auto &x=row[a];
//             auto &y=col[b];
//             auto pos1=lower_bound(x.begin(),x.end(),b);
//             bool left=pos1!=x.begin();
//             bool right=(next(pos1))!=x.end();
//             auto pos2=lower_bound(y.begin(),y.end(),a);
//             bool up=pos2!=y.begin();
//             bool down=(next(pos2))!=y.end();
//             if(left&&right&&up&&down){
//                 count++;
//                 cout<<a<<' '<<b<<endl;
//             }
//         }
//         return count;
//     }
// };

//         int s=buildings.size();
//         vector<vector<int>>temp(s,vector<int>(4,0));
//         for( int i=0;i<buildings.size()-1;i++){
//             for(int j=i+1;j<buildings.size();j++){
//                 int a=buildings[i][0]-buildings[j][0];
//                 int b=buildings[i][1]-buildings[j][1];
//                 if(b==0){
//                     if(a>0){
//                         temp[i][0]++;
//                         temp[j][1]++;
//                     }
//                     if(a<0){
//                         temp[j][0]++;
//                         temp[i][1]++;
//                     }
//                 }
//                 if(a==0){
//                     if(b>0){
//                         temp[i][3]++;
//                         temp[j][2]++;
//                     }
//                     if(b<0){
//                         temp[j][3]++;
//                         temp[i][2]++;
//                     }
//                 }

//             }
//         }//endcheck
        
//         int count=0;
//         for(int i=0;i<s;i++){
//             bool check =true;
//             for(int j=0;j<4;j++){
//                 if(temp[i][j]==0){
//                     check=false;
//                     break;
//                 }
//             }if(check)count++;
//         }
//         return count;

        
//     }
// };
