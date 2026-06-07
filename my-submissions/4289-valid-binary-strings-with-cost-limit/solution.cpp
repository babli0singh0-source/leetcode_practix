class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        for(int i=0;i<pow(2,n);i++){
            string s = bitset<12>(i).to_string();
            s = s.substr(12 - n);   // keep exactly n bits
            char prev = s[n-1];
            int sum = (prev=='1')?n-1:0;
            bool check = true;
            for(int j = n-2; j >= 0; j--) {
                if(s[j] == '1')sum += j;
                if(sum > k || (s[j] == prev && s[j] == '1')) {
                    check = false;
                    break;
                }
                prev = s[j];
            }
            if(check){
                ans.push_back(s);
            }
        }
        return ans;
    }
};
