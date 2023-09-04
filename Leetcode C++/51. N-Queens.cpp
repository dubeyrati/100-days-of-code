class Solution {
    vector<vector<string>> ans;
    vector<string> B;
    vector<bool> col, hill, dale;
    int n;
    void dfs(int i) {
        if (i == n) {
            ans.push_back(B);
            return;
        }
        for (int j = 0; j < n; ++j) {
            int h = i + j, d = i + n - 1 - j;
            if (col[j] || hill[h] || dale[d]) continue;
            col[j] = hill[h] = dale[d] = true;
            B[i][j] = 'Q';
            dfs(i + 1);
            B[i][j] = '.';
            col[j] = hill[h] = dale[d] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        B.assign(n, string(n, '.'));
        col.assign(n, false);
        hill.assign(2 * n - 1, false);
        dale.assign(2 * n - 1, false);
        dfs(0);
        return ans;