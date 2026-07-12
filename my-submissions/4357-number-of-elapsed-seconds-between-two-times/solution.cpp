class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string secs="",sece="";
        string mins="",mine="";
        string hrs="",hre="";
        secs.push_back(startTime[6]);
        secs.push_back(startTime[7]);
        mins.push_back(startTime[3]);
        mins.push_back(startTime[4]);
        hrs.push_back(startTime[0]);
        hrs.push_back(startTime[1]);
        
        sece.push_back(endTime[6]);
        sece.push_back(endTime[7]);
        mine.push_back(endTime[3]);
        mine.push_back(endTime[4]);
        hre.push_back(endTime[0]);
        hre.push_back(endTime[1]);

        int s1=stoi(secs);
        int s2=stoi(sece);

        int m1=stoi(mins);
        int m2=stoi(mine);

        int h1=stoi(hrs);
        int h2=stoi(hre);
        
        int ans=(s2+(m2*60)+(h2*60*60))-(s1+(m1*60)+(h1*60*60));
        return ans;
        
    }
};
