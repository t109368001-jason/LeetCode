class Solution {
 public:
  bool isMatch(string s, string p) {
    int                  n = s.size();
    int                  m = p.size();
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
    dp[0][0] = true;
    for (int i = 0; i < m; i++) {
      if (p[i] == '*' && dp[0][i - 1]) {
        dp[0][i + 1] = true;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (p[j] == '.') {
          dp[i + 1][j + 1] = dp[i][j];
        }
        if (p[j] == s[i]) {
          dp[i + 1][j + 1] = dp[i][j];
        }
        if (p[j] == '*') {
          if (p[j - 1] != s[i] && p[j - 1] != '.') {
            dp[i + 1][j + 1] = dp[i + 1][j - 1];
          } else {
            dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
          }
        }
      }
    }
    return dp[n][m];
  }
};