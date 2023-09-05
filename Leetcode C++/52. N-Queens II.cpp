class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n), hill(2 * n - 1), dale(2 * n - 1);

        function<int(int)> dfs = [&](int i) {
            
            if (i == n) return 1;
            int ans = 0;

            for (int j = 0; j < n; ++j) { 
                int h = i + j, d = i + n - 1 - j;
                if (col[j] || hill[h] || dale[d]) continue;
                col[j] = hill[h] = dale[d] = true;
                ans += dfs(i + 1);
                col[j] = hill[h] = dale[d] = false;
            }
            
            return ans;
        };
        return dfs(0);
    }
};