class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto &it: patterns){
            if(word.find(it)!=-1){
                ans++;
            }
        }
        return ans;
        // int n=word.size();
        // unordered_map<char,vector<int>>mpp;
        // for(int i=0;i<n;i++){
        //     mpp[word[i]].push_back(i);
        // }
        // int ans=0;
        // for(auto &it:patterns){
        //     int m=it.size();
        //     if(mpp.count(it[0])==0)continue;
        //     auto temp=mpp[it[0]];
        //     for(auto &ind:temp){
        //         string j=word.substr(ind,m);
        //         if(j==it){
        //             ans++;
        //             break;
        //         }
        //     }
        // }
        // return ans;
    }
};
