class Solution {
    int helper(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2){
        int a1=INT_MAX;
        for(int i=0;i<s1.size();i++){
            a1=min(a1,s1[i]+d1[i]);
        }
        int a2=INT_MAX;
        for(int j=0;j<s2.size();j++){
            a2=min(a2,max(s2[j],a1)+d2[j]);
        }
        return a2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l_w=helper(landStartTime,landDuration,waterStartTime,waterDuration);
        int w_l=helper(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(l_w,w_l);
    }
};
