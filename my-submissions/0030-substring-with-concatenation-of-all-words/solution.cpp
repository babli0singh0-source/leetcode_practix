class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty() || s.empty()) return {};
        unordered_map<string,int>mpp;
        for(auto &it:words){
            mpp[it]++;
        }
        int n=words.size();
        int len=words[0].size();
        int total=n*len;
        if(total > s.size()) return {};
        vector<int>ans;
        for(int offset=0;offset<len;offset++){
            int left=offset;
            int c=0;
            unordered_map<string,int>window;
            for(int right=offset;right<=s.size()-len;right+=len){
                string temp=s.substr(right,len);
                if(mpp.count(temp)){
                    window[temp]++;
                    c++;
                    while(window[temp]>mpp[temp]){
                        string leftword=s.substr(left,len);
                        window[leftword]--;
                        c--;
                        left=left+len;
                    }
                    if(c==n){
                        ans.push_back(left);
                        string leftword=s.substr(left,len);
                        window[leftword]--;
                        c--;
                        left=left+len;
                    }
                }else{
                    window.clear();
                    c=0;
                    left=len+right;
                }
            }
        }
        return ans;
    }
};
