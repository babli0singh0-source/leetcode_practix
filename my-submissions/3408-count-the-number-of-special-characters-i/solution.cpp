class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mpp;
        int ans=0;
        for(auto &ch : word){
            if(mpp.count(ch)==0){
                mpp[ch]++;
                if(ch>='a'&&ch<='z'&&mpp.count(toupper(ch)))ans++;
                else if(ch>='A'&&ch<='Z'&&mpp.count(tolower(ch)))ans++;
            }
        }
        return ans;
        
    }
};
