class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();
        for (int i = 1; i < strs.size() && len; ++i) {
            int j = 0, end = min(len, (int)strs[i].size());
            while (j < end && strs[0][j] == strs[i][j]) ++j;
            len = j;
        }
        return strs[0].substr(0, len);
    }
};