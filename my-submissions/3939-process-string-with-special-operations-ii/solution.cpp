class Solution {
public:
    char processStr(string s, long long k) {
        long long ansi=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                ansi++;
            }else if(s[i]=='*'){
                if(ansi!=-1){
                    ansi--;
                }
            }else if(s[i]=='#'){
                ansi=ansi*2+1;
            }else if(s[i]=='%'){
                continue;
            }
        }
        if(ansi<k) return '.';
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*'){// this has decresed the length previously 
                ansi++;//so we are increasing the length
            }else if (s[i]=='#'){//this duplicated the string so k is either in left half or right half
                if(k>ansi/2){//in the right half then we will decrease the k by this much 
                    k=k-(ansi+1)/2;
                    //if in left then k already in the range where we want 
                }
                ansi=ansi/2;
            }else if(s[i]=='%'){//if ans ch was at k then in reversed string it will be length-k
                k=ansi-k;
            }else{
                if(k==ansi)return s[i];
                else ansi--;
            }
        }
        return '.';
    }
};
