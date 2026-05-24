class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<int,int>mpp;
        int strength=0;
        for(auto &ch :password){
            if(mpp.count(ch)==0){
                mpp[ch]=1;
                if(ch>='a'&&ch<='z')strength+=1;
                else  if(ch>='A'&&ch<='Z')strength+=2;
                else if(ch>='0'&&ch<='9')strength+=3;
                else strength+=5;
            }else continue;
        }
        return strength;
    }
};
