class Solution {
private:
public:
    vector<int> findSubstring(string s, vector<string>& A) {
        if (A.empty()) return {};
        int L = A.size(), M = A[0].size(), last = s.size() - M * L;
        unordered_map<string, int> cnt;
        for (auto &w : A) ++cnt[w];
        vector<int> ans;
        function<bool(int, int)> dfs = [&](int i, int seen) {
            if (seen == L) return true;
            int &c = cnt[s.substr(i, M)];
            if (!c) return false;
            c--;
            bool ans = dfs(i + M, seen + 1);
            c++;
            return ans;
        };
        for (int i = 0; i <= last; ++i) {
            if (dfs(i, 0)) ans.push_back(i);
        }
        return ans;
    }
};