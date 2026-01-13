class Solution {
public:
    double areaAbove(double mid, vector<vector<int>>& squares) {
        double area = 0;
        for (auto &sq : squares) {
            double bottom = sq[1];
            double top = sq[1] + sq[2];
            double side = sq[2];

            if (mid <= bottom)
                area += side * side;
            else if (mid >= top)
                area += 0;
            else
                area += (top - mid) * side;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = -1e18;

        for (auto &sq : squares) {
            total += 1.0 * sq[2] * sq[2];
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }

        double target = total / 2.0;

        while (high - low > 1e-6) {
            double mid = (low + high) / 2;
            if (areaAbove(mid, squares) > target)
                low = mid;
            else
                high = mid;
        }

        return low; // minimum y
    }

    // double bs(double l,double h,double area,int s1t,int s2t,int l1,int l2){
    //     double mid,val;
    //     while(l<h){
    //         mid=(l+h)/2;
    //         val=(s1t-mid)*l1+(s2t-mid)*l2;
    //         if(val==area)return mid;
    //         else if(val>area){
    //             l=mid;
    //         }else h=mid;
    //     }
    //     return mid;
    // }
    // double separateSquares(vector<vector<int>>& squares) {
    //     double area1=squares[0][2]*squares[0][2],area2=squares[1][2]*squares[1][2],ans=0;
    //     int s1b=squares[0][1],s1t=squares[0][1]+squares[0][2],l1=squares[0][2];
    //     int s2b=squares[1][1],s2t=squares[1][1]+squares[1][2],l2=squares[1][2];
    //     if(s1t>=s2b){
    //         double l=s1b,h=s2t;
    //         ans=bs(l,h,(area1+area2)/2,s1t,s2t,l1,l2);
    //     }
    //     else{
    //         if(area1==area2)ans=s1t;
    //         else if(area1>area2) ans=bs(s1b,s2b,(area1+area2)/2,s1t,s2t,l1,l2);
    //         else ans=bs(s1t,s2t,(area1+area2)/2,s1t,s2t,l1,l2);
    //     }
    //     return ans;  
    // }
};
