class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int res = 0;
        while(diff!=0){
            diff = diff & diff-1;
            res++;
        }
        return res;
    }
};

// Bitwise XOR operator gives the bits that are different among the operands.
// Hence perform a bitwise operator on the start and goal and count the bits that are different