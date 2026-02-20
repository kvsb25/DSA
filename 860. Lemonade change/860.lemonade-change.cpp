class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for(auto bill:bills){
            if(bill == 5){
                five += 1;
            } else if(bill == 10){
                if(five){
                    five -= 1;
                    ten += 1;
                } else {
                    return false;
                }
            } else {
                if(ten && five){
                    ten -= 1;
                    five -= 1;
                } else if(five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

// keep track of notes 5, 10 and 20 (we need not to keep track of 20 as it is the maximum that someone would give and for the max the change would be 15, so max change never gonna exceed 15 hence we never give back 20 to anyone so no need to keep its track)
// only three possible notes that someone would give -> 5, 10 or 20
// if someone gives 5, no change to be returned
// if someone gives 10, 5 should be given as change. So we check, if we have $5 note then we give that and accept the $10 note else we can't return the change and can't sell the lemonade (return false)
// if someone gives 20, 15 should be given as change. So we check, if we have a $10 note and a $5 note or if we have greater than equal to 3 $5 notes. If both is false then we are not able to give the change and hence we cannot sell.