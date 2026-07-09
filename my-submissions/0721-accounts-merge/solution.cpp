class disjoint{
    public:
    vector<int>parent,size;
    disjoint( int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findup(int a){
        if(parent[a]==a)return a;
        return parent[a]=findup(parent[a]);
    }
    void ubsize(int a,int b){
        int upa=findup(a);
        int upb=findup(b);
        if(upa==upb)return;
        if(size[upa]>=size[upb]){
            parent[upb]=upa;
            size[upa]+=size[upb];
        }else{
            parent[upa]=upb;
            size[upb]+=size[upa];
        }
    }
    // void ubrank(int a,int b){
    //     int upa=findup(a);
    //     int upb=findup(b);
    //     if(upa==upb)return;
    //     if(rank[upa]>rank[upb]){
    //         parent[upb]=upa;
    //     }else if(rank[upa]<rank[upb]){
    //         parent[upa]=upb;
    //     }else{
    //         parent[upb]=upa;
    //         rank[upa]++;
    //     }
    // }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint dj(n+1);
        unordered_map<string ,int>mpp;
        for(int i=0;i<n;i++){
            int s=accounts[i].size();
            for(int j=1;j<s;j++){
                if(mpp.count(accounts[i][j])==0){
                    mpp[accounts[i][j]]=i;
                }else{
                    dj.ubsize(mpp[accounts[i][j]],i);
                }   
            }
        }
        vector<vector<string>>tempans(n);
        for(auto &it:mpp){
            string x=it.first;
            int ultimate=dj.findup(it.second);
            tempans[ultimate].push_back(x);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if (tempans[i].empty()) continue;
            sort(tempans[i].begin(), tempans[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); 
            temp.insert(temp.end(), tempans[i].begin(), tempans[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};
