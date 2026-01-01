class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool k=false;
        if(digits.size()==1){
            if(digits[0]==9)return {1,0};
            else digits[0]+=1;
            return digits;
        }
        for(int i=digits.size()-1;i>=0&&!k;i--){
            if(i==0&&digits[i+1]==0){
                digits[i]=0;
                digits.insert(digits.begin(),1);
            }
            else if(digits[i]!=9){
                digits[i]+=1;
                k=true;
            }
            else if(digits[i]==9&&digits[i-1]==9){
                digits[i]=0;
                continue;
            }
            else if(digits[i]==9&&digits[i-1]!=9){
                digits[i]=0;digits[i-1]+=1;k=true;
            }
        }
        return digits;
    }
};
