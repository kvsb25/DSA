class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3, -1);
        int ans= 0;

        for(int i = 0; i < s.size(); i++){
            // track the latest position of the current char
            mp[s[i]-'a'] = i;

            int temp = *min_element(mp.begin(), mp.end());

            if(temp != -1){
                ans += temp+1; // i + 1 = all the substrings ending at index 'i'.
            }
        }

        return ans;
    }
};
// bbabc: here abc being the combination where minimum ele in mp is not -1. the min is 2 which is the index of a, and hence 2+1 are the substrings ending with 'abc'
// so keeping track of lastest positions of a, b, c we get to know all the combinations of a, b, c of size 3 (the minimum size to have at least 1 occurrence of a, b, c)

// At index i, we know the latest positions of a, b, c. (in vector<int> mp, where indices 0,1,2 correspond to a,b,c)
// The one that appeared earliest among them decides how many starts are possible.
// Starts from 0 to that index all give a valid substring ending at i.
// So add (that index + 1) to answer.