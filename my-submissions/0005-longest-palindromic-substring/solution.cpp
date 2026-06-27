class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int right=n-1;right>=i;){
                //cout<<right<<endl;
                int left=i;
                int x=-1;
                if(s[left]==s[right]){
                    string temp=s.substr(left,right+1-left);
                    left++;
                    right--;
                    while(left<=right){
                        if(x==-1&&s[i]==s[right])x=right+1;
                        if(s[left]!=s[right]){
                            temp="";
                            right=right+1;
                            break;
                        }
                        left++;
                        right--;
                    }
                    if(temp.size()>ans.size())ans=temp;
                    if(temp==""&&x!=-1)right=x;
                }
                right--;
            }
            if(ans.size()>=n-i)break;
        }
        return ans;
    }
};
