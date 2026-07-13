class disjoint{
    public:
    vector<int>parent,size;
    disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findupar(int a){
        if(parent[a]==a)return a;
        return parent[a]=findupar(parent[a]);
    }
    void unionbysize(int a,int b){
        int upa=findupar(a);
        int upb=findupar(b);
        if(upa==upb)return;
        if(size[upa]>=size[upb]){
            parent[upb]=upa;
            size[upa]+=size[upb];
        }else{
            parent[upa]=upb;
            size[upb]+=size[upa];
        }
        return;
    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjoint dj(n*n+1);
        int ans=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1){
                    int n1=n*r+c;
                    for(int i=0;i<4;i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];
                        if(nr>=0&&nc>=0&&nr<n&&nc<n&&grid[nr][nc]==1){
                            int n2=nr*n+nc;
                            dj.unionbysize(n1,n2);
                        }
                    }
                    int k=dj.findupar(n1);
                    ans=max(ans,dj.size[k]);
                }
            }
        }
        
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0){
                    int n1=n*r+c;
                    int temp=1;
                    set<int>neighbour;
                    for(int i=0;i<4;i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];
                        if(nr>=0&&nc>=0&&nr<n&&nc<n&&grid[nr][nc]==1){
                            int n2=nr*n+nc;
                            int k=dj.findupar(n2);
                            neighbour.insert(k);
                        }
                    }
                    for(auto &it:neighbour){
                        temp+=dj.size[it];
                    }
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
