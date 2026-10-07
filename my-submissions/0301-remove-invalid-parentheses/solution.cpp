// class Solution {
// public:
//     vector<string> removeInvalidParentheses(string s) {
//         int left=0;
//         int valid=0;
//         string ans="";
//         for(int i=0;i<s.size();i++){
//             if(valid==0){
//                 ans=ans+s.substr(left,i-left+1);
//                 left=i+1;
//             }else if(valid<0){
//                 left=
//             }
//             if(s[i]=='('){
//                 valid++;
//             }else if(s[i]==')'){
//                 valid--;
//             }
//         }
//     }
// };

class Solution {
    void remove(string s, int scanStart, int deleteStart, char open, char close,
                vector<string>& answers) {
        int balance = 0;

        for (int i = scanStart; i < (int)s.size(); i++) {
            if (s[i] == open) {
                balance++;
            } else if (s[i] == close) {
                balance--;
            }

            if (balance >= 0) {
                continue;
            }

            for (int j = deleteStart; j <= i; j++) {
                if (s[j] == close && (j == deleteStart || s[j - 1] != close)) {
                    remove(s.substr(0, j) + s.substr(j + 1), i, j, open, close,
                           answers);
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if (open == '(') {
            remove(s, 0, 0, ')', '(', answers);
        } else {
            answers.push_back(s);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answers;
        remove(s, 0, 0, '(', ')', answers);
        return answers;
    }
};
