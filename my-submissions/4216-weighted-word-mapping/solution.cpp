class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &it:words){
            int weight=0;
            for(char &ch:it){
                weight+=weights[(ch-'a')];
            }
            weight=weight%26;
            char x='z'-weight;
            ans.push_back(x);
        }
        return ans;
    }
};
