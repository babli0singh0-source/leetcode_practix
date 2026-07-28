class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>hash(26,0);
        for(char &ch:s){
            hash[ch-'a']++;
        }
        string central="";
        string ans="";
        for(int i=0;i<26;i++){
            if(hash[i]%2==1){
                central=i+'a';
                hash[i]--;
            }
            hash[i]/=2;
            while(hash[i]>0){
                ans.push_back(i+'a');
                hash[i]--;
            }
        }
        string temp=ans;
        reverse(ans.begin(),ans.end());
        return temp+central+ans;
    }
};
