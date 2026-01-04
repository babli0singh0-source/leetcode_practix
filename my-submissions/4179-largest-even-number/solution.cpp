class Solution {
public:
    string largestEven(string s) {
        while(s.size()!=0){
            if((s[s.size()-1]-0)%2==0){
                return s;
            }else s.pop_back(); 
        }
        return s;    
    }
};
