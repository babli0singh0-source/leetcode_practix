class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int turn =0;//alice 1 for bob
        int n=stones.size();
        vector<int>vec(3,0);
        for(int &it:stones){
            vec[it%3]++;
        }
        bool maybe=(vec[0]%2>0);
        if(vec[1]==0){
            return vec[2]<3?false:maybe;
        }
        if(vec[2]==0){
            return vec[1]<3?false:maybe;
        }
        if(abs(vec[1]-vec[2])>2)return true;
        return !maybe;
    }
};
