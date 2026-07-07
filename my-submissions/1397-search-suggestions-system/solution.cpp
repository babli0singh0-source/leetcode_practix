class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n=products.size();
        vector<vector<string>>ans;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[i]=0;
        }
        for(int i=0;i<searchWord.size();i++){
            char ch=searchWord[i];
            vector<string>temp;
            int cnt=0;
            for(auto it=mpp.begin();it!=mpp.end();){
                auto &[ind,key]=*it;
                if(products[ind][key]==ch){
                    if(cnt<3){
                        temp.push_back(products[ind]);
                        cnt++;
                    }
                    key++;
                    it++;
                }
                else it=mpp.erase(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
