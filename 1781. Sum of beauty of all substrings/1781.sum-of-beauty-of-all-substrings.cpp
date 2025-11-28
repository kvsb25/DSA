class Solution {
public:
    int beauty(unordered_map<char, int>& map) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (auto ele : map) {
            if (ele.second > maxi)
                maxi = ele.second;
            if (ele.second < mini)
                mini = ele.second;
        }

        return maxi - mini;
    }

    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int sum = 0;
            unordered_map<char, int> map;
            for (int j = i; j < s.length(); j++) {
                map[s[j]]++;
                sum += beauty(map);
            }
            res += sum;
        }
        return res;
    }
};

// in strings it is generally hard to achieve a linear time complexity