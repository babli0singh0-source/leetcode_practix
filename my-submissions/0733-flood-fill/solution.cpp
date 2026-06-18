class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int starting=image[sr][sc];
        image[sr][sc]=color;
        if(starting== color) return image;
        vector<int>dr={1,0,-1,0};
        vector<int>dc={0,-1,0,1};
        int n=image.size();
        int m=image[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==starting){
                    q.push({nr,nc});
                    image[nr][nc]=color;
                }
            }
        }
        return image;
    }
};
