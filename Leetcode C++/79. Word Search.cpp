class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int M = board.size(), N = board[0].size(), dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        function<bool(int, int, int)> dfs = [&](int x, int y, int i) {
            if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != word[i]) return false;
            if (i + 1 == word.size()) return true;
            char c = board[x][y];
            board[x][y] = 0;

            for (auto &[dx, dy] : dirs) {
                if (dfs(x + dx, y + dy, i + 1)) return true;
            }

            board[x][y] = c;
            
            return false;
        };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};