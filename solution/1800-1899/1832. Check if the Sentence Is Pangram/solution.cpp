class Solution {
 public:
  bool checkIfPangram(string sentence) {
    vector<bool> dp(26);
    for (char c : sentence) {
      dp[c - 'a'] = true;
    }
    return all_of(dp.begin(), dp.end(), [](bool b) { return b; });
  }
};