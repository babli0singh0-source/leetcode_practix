class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hangle=(1.0*hour*30)+(1.0*minutes/2);
        double minuteangle =1.0*minutes*6;
        double ans=abs(hangle-minuteangle);
        return min(360-ans,ans);
        
    }
};
