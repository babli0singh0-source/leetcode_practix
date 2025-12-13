class Solution {
public:
    static bool customsort(pair<string,string>a,pair<string,string>b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>v;
        for (int i=0;i<code.size();i++){
            bool check=true;
            if(code[i]=="")continue;
            for(auto &ch:code[i]){
                if(!(isalnum(ch)||ch=='_')){
                    check=false;
                }
            }
            if(check){
                if(businessLine[i]=="electronics"|| businessLine[i]=="grocery"||businessLine[i]== "pharmacy"||businessLine[i]== "restaurant"){
                    if(isActive[i]) v.push_back({businessLine[i],code[i]});
                }
            }
        }
        sort(v.begin(),v.end(),customsort);
        vector<string>ans;
        for(auto &it:v){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
