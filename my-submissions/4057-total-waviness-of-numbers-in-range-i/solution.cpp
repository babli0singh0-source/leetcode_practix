class Solution {
public:
    int totalWaviness(int num1, int num2) {
        string temp="";
        int count=0;
        for(int i=max(101,num1);i<=num2;i++){
            temp=to_string(i);
            for(int j=1;j<temp.size()-1;j++){
                if(temp[j]<temp[j-1]&&temp[j]<temp[j+1])count++;
                else if (temp[j]>temp[j-1]&&temp[j]>temp[j+1])count++;
            }
        }
        return count;
    }
};
