class Solution {
public:
    int bestClosingTime(string customers) {
        int yc=0;
        for(auto &ch:customers){
            if(ch=='Y')yc++;
        }
        int ansv=yc,ansi=0,vn=0,vy=0;
        if(ansv==0)return ansi;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N')vn++;
            if(customers[i]=='Y')vy++;
            int penalty=vn+yc-vy;
            if(penalty<ansv){
                ansi=i+1;
                ansv=penalty;
            }
        }
        return ansi;    
    }
};
