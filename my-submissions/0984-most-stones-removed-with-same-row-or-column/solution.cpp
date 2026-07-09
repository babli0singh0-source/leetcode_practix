class disjoint{
    public:
    vector<int>size,parent;
    disjoint(int n){
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
    void ubs(int a,int b){
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
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int rowmax=0;
        int colmax=0;
        for(auto &it:stones){
            rowmax=max(rowmax,it[0]);
            colmax=max(colmax,it[1]);
        }
        int n=rowmax+colmax+2;
        disjoint dj(n);
        unordered_set<int>st;
        for(auto &it:stones){
            dj.ubs(it[0],it[1]+rowmax+1);
            st.insert(it[0]);
            st.insert(it[1]+rowmax+1);
        }
        int count=0;
        for(auto &i:st){
            if(dj.findup(i)==i)count++;
        }
        return stones.size()-count;
    }
};
