class Solution {
public:
    int maxDistance(string moves) {
        int hz=0;
        int ver=0;
        int under=0;
        int dis=0;
        for(auto &ch:moves){
            if(ch=='D')ver--;
            else if(ch=='U')ver++;
            else if(ch=='L')hz++;
            else if(ch=='R')hz--;
            else if(ch=='_')under++;
        }
        dis=abs(hz)+abs(ver)+under;
        return dis;
    }
};
