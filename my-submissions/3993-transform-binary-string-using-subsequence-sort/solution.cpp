class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int onesS = 0;
        for(char c : s)onesS += (c == '1');
        int n = s.size();
        vector<bool> ans;
        for(string &t : strs) {
            int fixedOnes = 0, ques = 0;
            for(char c : t){
                if(c == '1') fixedOnes++;
                else if(c == '?') ques++;
            }
            
            if(fixedOnes > onesS || fixedOnes + ques < onesS){
                ans.push_back(false);
                continue;
            }

            int need = onesS - fixedOnes;
            int remQ = ques;

            int prefS = 0;
            int prefT = 0;
            bool ok = true;

            for(int i = 0; i < n; i++){
                if(s[i] == '1') prefS++;
                if(t[i] == '1') prefT++;
                
                else if(t[i] == '?'){
                    remQ--;
                    if(need > remQ){
                        prefT++;
                        need--;
                    }
                }

                if(prefT > prefS){
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok && need == 0);
        }

        return ans;
    }
};
