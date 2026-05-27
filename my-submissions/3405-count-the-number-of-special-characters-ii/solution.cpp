class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mppu,mppl;
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a'&&word[i]<='z')mppl[word[i]]=i;
            else if(mppu.count(word[i])==0)mppu[word[i]]=i;
        }
        for(auto &it:mppu){
            char ch=tolower(it.first);
            if(mppl.count(ch)&&mppl[ch]<it.second)ans++;
        }
        return ans;  
    }
};
