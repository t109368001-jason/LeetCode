class Solution {
  int                 m;
  int                 n;
  vector<vector<int>> dp;

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    m           = matrix.size();
    n           = matrix[0].size();
    dp          = vector<vector<int>>(m, vector<int>(n, 0));
    int maxPath = 0;
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        maxPath = max(maxPath, solve(matrix, r, c, -1));
      }
    }
    return maxPath;
  }

  int solve(vector<vector<int>>& matrix, int r, int c, int prev) {
    if (r < 0 || c < 0 || r >= m || c >= n || matrix[r][c] <= prev) {
      return 0;
    }
    auto& maxPath = dp[r][c];
    if (maxPath) {
      return maxPath;
    }
    maxPath = 1 + max({solve(matrix, r + 1, c, matrix[r][c]), solve(matrix, r - 1, c, matrix[r][c]),
                       solve(matrix, r, c + 1, matrix[r][c]), solve(matrix, r, c - 1, matrix[r][c])});
    return maxPath;
  }
};