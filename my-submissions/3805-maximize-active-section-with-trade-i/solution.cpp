class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>temp;
        int c=1;
        char no=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==no){
                c++;
            }else{
                if(no=='1'){
                    temp.push_back(c);
                }else{
                    temp.push_back(-c);
                }
                c=1;
                no=s[i];
            }
        }
        if(no=='1')temp.push_back(c);
        else temp.push_back(-c);

        int fin=0;
        int i=0,ind=-1;
        int n=temp.size();
        while(i<n){
            if(temp[i]<0&&i+2<n){
                int ans=abs(temp[i]+temp[i+2]);
                fin=max(fin,ans);
            }
            i++;
        }
        for(int i=0;i<n;i++){
            if(temp[i]>0){
                fin+=temp[i];
            }
        }
        return fin;
    }
};
