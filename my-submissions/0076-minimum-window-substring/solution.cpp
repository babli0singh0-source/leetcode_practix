class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mpp(126,0);
        for(char &ch:t){
            mpp[ch]++;
        }
        int m=t.size();
        int count=0;
        int ind=-1,minlen=INT_MAX;
        int left=0,right=0,n=s.size();
        while(right<n){
            if(mpp[s[right]]>0){
                count++;
            }
            mpp[s[right]]--;
            while(count==m){
                int len=right-left+1;
                if(len<minlen){
                    ind=left;
                    minlen=len;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return ind==-1?"":s.substr(ind,minlen);
    }
};
