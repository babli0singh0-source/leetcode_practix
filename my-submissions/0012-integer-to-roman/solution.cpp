class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int n=num/1000;
        while(n>0){
            ans+='M';
            n--;
        }
        num=num%1000;
        n=num/100;
        if(n==9)ans+="CM";
        else if(n==4)ans+="CD";
        else if(n!=0){
            while(n>0&&n<4){
                ans+='C';
                n--;
            }
            if(n>=5)ans+='D';
            while(n>5&&n<9){
                ans+='C';
                n--;
            }
        }
        num=num%100;
        n=num/10;
        if(n==9)ans+="XC";
        else if(n==4)ans+="XL";
        else if(n!=0){
            while(n>0&&n<4){
                ans+='X';
                n--;
            }
            if(n>=5)ans+='L';
            while(n>5&&n<9){
                ans+='X';
                n--;
            }
        }
        n=num%10;
        if(n==9)ans+="IX";
        else if(n==4)ans+="IV";
        else if(n!=0){
            while(n>0&&n<4){
                ans+='I';
                n--;
            }
            if(n>=5)ans+='V';
            while(n>5&&n<9){
                ans+='I';
                n--;
            }
        }
        return ans;

    }
};
