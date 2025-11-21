class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size()-1;
        while(i+1>0){
            if((num[i] - 48)%2 != 0){
                return num.substr(0, i+1);
            }
            i--;
        }
        return "";
    }
};