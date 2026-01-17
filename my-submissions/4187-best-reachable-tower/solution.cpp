class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int xa=-1,ya=-1,ans=-1;
        for(int i=0;i<towers.size();i++){
            int dist=abs(towers[i][0]-center[0])+abs(towers[i][1]-center[1]);
            if(dist<=radius){
                int x = towers[i][0];
                int y = towers[i][1];
                if (towers[i][2] > ans ||
                   (towers[i][2] == ans && (x < xa || (x == xa && y < ya)))) {
                    ans = towers[i][2];
                    xa = x;
                    ya = y;
                }
            }
        }
        return {xa,ya};
        
    }
};
