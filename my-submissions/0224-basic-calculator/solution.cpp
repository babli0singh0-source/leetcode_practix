class Solution {
    unordered_map<int,pair<int,long long>>mpp;
    int solve(string &s,int left,int right,vector<bool>&v){
        long long value=0;
        left++;
        long long x=0;
        char prev='m';
        while(left<=right){
            if(s[left]==' ');
            else if(v[left]==true){
                x=mpp[left].second;
                left=mpp[left].first;
            }else if(s[left]!='+'&&s[left]!='-'&&s[left]!=')'){
                x=x*10+(s[left]-'0');
            }
            else if(s[left]=='+'||s[left]=='-'||s[left]==')'){
                if(prev=='+'){
                    value=value+x;
                }else if(prev=='-'){
                    value=value-x;
                }else{
                    value=x;
                } 
                prev=s[left];
                x=0;
            }
            left++;
        }
        return value;
    }
public:
    int calculate(string s) {
        s='('+s+')';
        queue<int>q;
        vector<int>left;
        int n=s.size();
        vector<bool>v(n,false);
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch==' ')continue;
            else if(ch=='('){
                left.push_back(i);
            }
            else if(ch==')'){
                mpp[left.back()]={i,0};
                q.push(left.back());
                left.pop_back();
            }
        }
        while(!q.empty()){   
            int left=q.front();
            q.pop();            
            int right=mpp[left].first;             
            long long val=solve(s,left,right,v);                     
            mpp[left]={right,val};             
            v[left]=true;         
        }
        return (int)mpp[0].second;
    }
};
