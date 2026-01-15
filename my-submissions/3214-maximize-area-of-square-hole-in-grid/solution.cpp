class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int count=1,h=1,v=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                count++;
            }else count=1;
            h=max(count,h);
        }
        count=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                count++;
            }else count=1;
            v=max(count,v);
        }
        int l=min(h + 1, v + 1);
        return l*l;
        
    }
};
