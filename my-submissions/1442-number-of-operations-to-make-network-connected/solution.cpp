class disjoint{
    public:
    vector<int>parent,size;
    disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        //parents self nodes self parents 
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findup(int a){
        if(parent[a]==a)return a;
        return parent[a]= findup(parent[a]);
    }
    void unionbysize(int a,int b){
        int upa=findup(a);
        int upb=findup(b);
        //if already connected then same ultimate parent
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint dj(n);
        int extra=0;
        for(auto &query:connections){
            if(dj.findup(query[0])==dj.findup(query[1]))extra++;
            else {
                dj.unionbysize(query[0],query[1]);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(dj.findup(i)==i)comp++;
        }
        int ans=comp-1;
        if(extra>=ans)return ans;
        return -1;
    }
};
