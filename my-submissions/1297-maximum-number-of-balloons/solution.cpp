class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>v(26,0);
        for(char &ch:text){
            v[ch-'a']++;
        }
        int mini=INT_MAX;
        string b="balloon";
        for(char &ch:b){
            if(ch=='l'||ch=='o'){
                mini=min(mini,v[ch-'a']/2);
            }else {
                mini=min(mini,v[ch-'a']);
            }
        }
        return mini;
    }
};
