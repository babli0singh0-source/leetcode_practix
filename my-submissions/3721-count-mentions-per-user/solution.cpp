
class Solution {
public:
    static bool customsort(vector<string>& a,vector<string>& b){
        int d1=stoi(a[1]);
        int d2=stoi(b[1]);
        if(d1!=d2)return d1<d2;
        auto s1=a[0];
        auto s2=b[0];
        if(s1=="OFFLINE"&&s2=="MESSAGE")return true;
        if(s1=="MESSAGE"&&s2=="OFFLINE")return false;
        return false;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),customsort);
        vector<int>mention(numberOfUsers,0);
        vector<string>onoffcheck(numberOfUsers,"ONLINE");
        unordered_map<int,int>mpp;
        for(int j=0;j<events.size();j++){
            auto a=events[j][0];
            auto b=events[j][1];
            auto c=events[j][2];
            if(a=="OFFLINE"){
                onoffcheck[stoi(c)]="OFFLINE";
                mpp[stoi(c)]=stoi(b);   
            }
            else if(a=="MESSAGE"){
                vector<int> toErase;
                for (auto &p : mpp) {
                    if (stoi(b) >= p.second + 60) {
                        onoffcheck[p.first] = "ONLINE";
                        toErase.push_back(p.first);
                    }
                }
                for (int k : toErase) mpp.erase(k);

                if(c=="ALL"){
                    for(int i=0;i<mention.size();i++) mention[i]++;
                }else if (c=="HERE"){
                    for(int i=0;i<mention.size();i++){
                        if(onoffcheck[i]=="ONLINE") mention[i]++; 
                    }
                }else {
                    stringstream ss(c);
                    string token;
                    while (ss >> token) {
                        int id = stoi(token.substr(2));   // remove "id"
                        mention[id]++;
                    }
                }
            }
        }
        return mention;   
    }
};
