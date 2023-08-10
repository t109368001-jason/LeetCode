class Solution {
 public:
  int longestSubstring(string s, int k) {
    if (s.empty() || s.size() < k) {
      return 0;
    }
    unordered_map<int, vector<int>> indicesMap;
    for (int i = 0; i < s.size(); i++) {
      indicesMap[s[i]].push_back(i);
    }
    vector<int> breakPoints;
    for (auto [c, indices] : indicesMap) {
      if (indices.size() != 0 && indices.size() < k) {
        for (int breakPoint : indices) {
          breakPoints.push_back(breakPoint);
        }
      }
    }
    if (breakPoints.empty()) {
      return s.size();
    }
    sort(breakPoints.begin(), breakPoints.end());
    int maxSum = longestSubstring(s.substr(0, breakPoints[0]), k);
    for (int i = 1; i < breakPoints.size(); i++) {
      int l     = breakPoints[i - 1];
      int r     = breakPoints[i];
      int count = r - l - 1;
      if (count > maxSum) {
        int currSum = longestSubstring(s.substr(l + 1, count), k);
        maxSum      = max(maxSum, currSum);
      }
    }
    int last = breakPoints[breakPoints.size() - 1];
    maxSum   = max(maxSum, longestSubstring(s.substr(last + 1, s.size() - last - 1), k));
    return maxSum;
  }
  // first success 100%/45%
  int longestSubstring1(string s, int k) {
    if (s.empty() || s.size() < k) {
      return 0;
    }
    vector<vector<int>> indices(26);
    for (int i = 0; i < s.size(); i++) {
      indices[s[i] - 'a'].push_back(i);
    }
    vector<int> breakPoints;
    for (int i = 0; i < 26; i++) {
      if (indices[i].size() != 0 && indices[i].size() < k) {
        for (int breakPoint : indices[i]) {
          breakPoints.push_back(breakPoint);
        }
      }
    }
    if (breakPoints.empty()) {
      return s.size();
    }
    for (int i = 0; i < breakPoints.size(); i++) {
      cout << breakPoints[i] << ", ";
    }
    cout << endl;
    sort(breakPoints.begin(), breakPoints.end());
    int maxSum = longestSubstring(s.substr(0, breakPoints[0]), k);
    for (int i = 1; i < breakPoints.size(); i++) {
      int l     = breakPoints[i - 1];
      int r     = breakPoints[i];
      int count = r - l - 1;
      if (count > maxSum) {
        int currSum = longestSubstring(s.substr(l + 1, count), k);
        maxSum      = max(maxSum, currSum);
      }
    }
    int last = breakPoints[breakPoints.size() - 1];
    maxSum   = max(maxSum, longestSubstring(s.substr(last + 1, s.size() - last - 1), k));
    return maxSum;
  }
};