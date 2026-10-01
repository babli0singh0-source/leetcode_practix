class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a1=rec1[0],b1=rec1[1],a2=rec1[2],b2=rec1[3];
        int x1=rec2[0],y1=rec2[1],x2=rec2[2],y2=rec2[3];
        if(a1==a2||b1==b2||x1==x2||y1==y2)return false;
        return !(a2<=x1||   // left
                 b2<=y1||   // bottom
                 a1>=x2||   // right
                 b1>=y2);    // top
    }
};
