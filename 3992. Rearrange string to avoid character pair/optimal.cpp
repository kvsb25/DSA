class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string xs = "", ys = "", temp = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == y){
                ys += s[i];
            } else if(s[i] == x){ 
                xs += s[i];
            } else {
                temp += s[i];
            }
        }

        return ys+xs+temp;
    }
};