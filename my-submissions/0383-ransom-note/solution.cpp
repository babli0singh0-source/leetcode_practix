class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int>mpp;
        for(auto &it:magazine){
            mpp[it]++;
        }
        for(auto &it: ransomNote){
            if(!mpp.count(it))return false;
            else {
                mpp[it]--;
                if(mpp[it]==0) mpp.erase(it);
            }
        }
        return true;
        
    }
};
