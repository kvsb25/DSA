class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                min += 1;
                max += 1;
            } else if(s[i] == ')'){
                min -= 1;
                max -= 1;
            } else {
                min -= 1;
                max += 1;
            }

            if(min < 0) min = 0;
            if(max < 0) return false;
        }

        return (min == 0);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
// N = length of string

// due to asteriks we can keep track of the range of all possible values of count after traversing the whole string. The minimum value the count can be and the maximum value the count can be after traversing the whole string
// hence the mininmum value in the range is denoted by min,
// and the maximum value in the range is denoted by max
// open parenthesis increases the count (both max and min of range ++ as it is sure that the range is going to increase due to open paranthesis)
// closed parenthesis decreases the count (both max and min of range -- as it is sure that the range is going to decrease due to close parenthesis)
// if the count is 0 then the parenthesis is valid as count was balanced to '0'
// but if there is an asteriks, it can be either open, closed parenthesis or empty string.
// so asteriks contributes to the range of counts as follows: min -= 1 and max += 1 as it can be a closing parenthesis to decrease the count or it can be an opening parenthesis to increase the count.