class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1), ans;
        for (int i = 0, N = s.size(); i < N; ++i) {
            char d = s[i];
            int cnt = 1;
            while (i + 1 < N && s[i + 1] == s[i]) ++i, ++cnt;
            ans += to_string(cnt) + d;
        }
        return ans;
    }
};