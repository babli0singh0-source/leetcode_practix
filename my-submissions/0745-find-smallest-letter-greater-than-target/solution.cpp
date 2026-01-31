class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans1=INT_MAX,ans2=INT_MIN;
        bool check=false;
        char ch1,ch2;
        for(int i=0;i<letters.size();i++){
            if(letters[i]-target>0){
                if(letters[i]-target<ans1){
                    ans1=letters[i]-target;
                    ch1=letters[i];
                    check=true;
                }
            }else {
                if(target-letters[i]>ans2){
                    ans2=target-letters[i];
                    ch2=letters[i];
                }
            }
        }
        
        if(check)return ch1;
        return ch2;
    }
};
