class Solution {
public:
     int lengthOfLongestSubstring(string s) {
        int i = 0, len = 0;
        unordered_map<char, int> dict;
        for (int j=0; j<s.size(); j++) {
            if (dict.find(s[j]) != dict.end()) {
                i = max(i, dict[s[j]] + 1);
            }
            dict[s[j]] = j;
            len = max(len, j - i + 1);
        }
        return len;
    }
};