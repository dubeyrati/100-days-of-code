class Solution {
    vector<string> ans, tmp;
    unordered_set<string> st;
    void dfs(string &s, int i) {
        if (i == s.size()) {
            string n;
            for (auto &t : tmp) {
                n += (n.size() ? " " : "") + t;
            }
            ans.push_back(n);
        }
        for (int j = i + 1; j <= s.size(); ++j) {
            auto sub = s.substr(i, j - i);
            if (st.count(sub) == 0) continue;
            tmp.push_back(sub);
            dfs(s, j);
            tmp.pop_back();
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        st = unordered_set<string>(begin(dict), end(dict));
        dfs(s, 0);
        return ans;
    }
};