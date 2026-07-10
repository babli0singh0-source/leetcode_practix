class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        priority_queue<pair<int,char>>pq;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>((n+1)/2))return "";
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0)pq.push({freq[i],i+'a'});
        }
        string ans="";
        char prev;
        while(!pq.empty()){
            auto [no1,curr1]=pq.top();
            pq.pop();
            if(curr1!=prev){
                ans.push_back(curr1);
                prev=curr1;
                if(no1-1>0)pq.push({no1-1,curr1});
            }else{
                auto [no2,curr2]=pq.top();
                pq.pop();
                ans.push_back(curr2);
                prev=curr2;
                pq.push({no1,curr1});
                if(no2-1>0)pq.push({no2-1,curr2});
            }
        }
        if(pq.size()>0)return "";
        return ans;
    }
};
