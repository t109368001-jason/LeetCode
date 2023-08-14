class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int r = 1; r < m; r++) {
      for (int c = 1; c < n; c++) {
        dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};