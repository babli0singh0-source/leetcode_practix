class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum=mass;
        multiset<int>mst;
        for(int i=0;i<asteroids.size();i++){
            mst.insert(asteroids[i]);
        }
        for(auto &it:mst){
            if(sum<it)return false;
            sum+=it;
        }
        // sort(asteroids.begin(),asteroids.end());
        // for(int i=0;i<asteroids.size();i++){
        //     if(sum<asteroids[i])return false;
        //     sum+=asteroids[i];
        // }
        return true;
        
    }
};
