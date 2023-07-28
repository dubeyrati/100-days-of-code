class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "" || s.empty()) {
            return 0;}
        int start = 0;
        int end = 0;
        int maxLength = 0;
        set<char> uniqueCharacters;
        while (end < s.length()) {
            if (uniqueCharacters.insert(s.at(end)).second) {
                end++;
                maxLength = max(maxLength, (int)uniqueCharacters.size());
            } else {
                uniqueCharacters.erase(s.at(start));
                start++;
            }
        }
        return maxLength;

    }
};