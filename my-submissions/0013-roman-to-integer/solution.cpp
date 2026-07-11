class Solution {
    void setvalues(unordered_map<string,int>&mpp){
        mpp["I"]=1;
        mpp["V"]=5;
        mpp["IV"]=4;
        mpp["X"]=10;
        mpp["IX"]=9;
        mpp["L"]=50;
        mpp["C"]=100;
        mpp["D"]=500;
        mpp["M"]=1000;
        mpp["XL"]=40;
        mpp["XC"]=90;
        mpp["CD"]=400;
        mpp["CM"]=900;
    }
public:
    int romanToInt(string s) {
        unordered_map<string,int>mpp;
        setvalues(mpp);
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            string temp="";
            temp.push_back(s[i]);
            string temp2=temp;
            if(i+1<n){
                temp.push_back(s[i+1]);
                if(mpp.count(temp)){
                    ans+=mpp[temp];
                    i++;
                }
                else ans+=mpp[temp2];
            }else {
                ans+=mpp[temp2];
            }
        }
        return ans;
    }
};
