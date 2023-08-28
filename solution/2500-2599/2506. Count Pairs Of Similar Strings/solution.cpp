class Solution {
 public:
  // map 97%/97%
  int similarPairs(vector<string>& words) {
    int                     ans = 0;
    unordered_map<int, int> freq;
    for (auto& word : words) {
      int mask = 0;
      for (auto& c : word) mask |= 1 << (c - 'a');
      ans += freq[mask]++;
    }
    return ans;
  }
  // vector 99%/95%
  int similarPairs1(vector<string>& words) {
    vector<int> dp(words.size());
    for (int i = 0; i < words.size(); i++) {
      auto& word = words[i];
      for (char c : word) {
        dp[i] |= (1 << (c - 'a'));
      }
    }
    int count = 0;
    for (int i = 0; i < dp.size(); i++) {
      for (int j = i + 1; j < dp.size(); j++) {
        if (dp[i] == dp[j]) {
          count++;
        }
      }
    }
    return count;
  }
};