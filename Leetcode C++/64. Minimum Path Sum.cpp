class Solution {
public:

    int minPathSum(vector<vector<int>>& A) {
       
       int M = A.size(), N = A[0].size();

        for (int i = 0; i < M; ++i) {

            for (int j = 0; j < N; ++j) {

                int sum = min(i - 1 >= 0 ? A[i - 1][j] : INT_MAX, j - 1 >= 0 ? A[i][j - 1] :  INT_MAX);
                A[i][j] += sum == INT_MAX ? 0 : sum;
            }
        }

        return A[M - 1][N - 1]; 
    }
};