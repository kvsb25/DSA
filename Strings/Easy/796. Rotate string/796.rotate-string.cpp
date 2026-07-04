// approach 1
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m){
            return false;
        }
        
        // right rotate the string and check if each rotation matches the goal
        for(int i = 0; i < n; i++){
            string temp = "";
            temp += s[n-1];
            temp += s.substr(0, n-1);
            if(temp == goal) return true;
            s = temp;
        }
        return false;
    }
};

// approach 2

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m){
            return false;
        }
        
        s += s;

        return strstr(s.c_str(), goal.c_str());
    }
};