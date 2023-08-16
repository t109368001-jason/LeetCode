// DFS DP 100%/84%
class Solution {
  int                             n;
  int                             m;
  unordered_map<int, vector<int>> dp;

 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    n  = s.size();
    m  = wordDict.size();
    dp = {};

    vector<string> result;
    vector<int>    wordIndices;
    wordBreak(0, s, wordDict, result, wordIndices);
    return result;
  }

  void wordBreak(int i, string& s, vector<string>& wordDict, vector<string>& result, vector<int>& wordIndices) {
    if (i > s.size()) {
      return;
    }
    if (i == s.size()) {
      string tmp;
      for (int jj = 0; jj < wordIndices.size(); jj++) {
        if (jj != 0) {
          tmp += " ";
        }
        tmp += wordDict[wordIndices[jj]];
      }
      result.push_back(tmp);
      return;
    }
    auto it = dp.find(i);
    if (it != dp.end()) {
      for (int j : it->second) {
        wordIndices.push_back(j);
        wordBreak(i + wordDict[j].size(), s, wordDict, result, wordIndices);
        wordIndices.pop_back();
      }
      return;
    }
    for (int j = 0; j < m; j++) {
      auto& word = wordDict[j];
      int   wLen = word.size();
      if (n - i < wLen) {
        continue;
      }
      if (strncmp(&s[i], &word[0], wLen) != 0) {
        continue;
      }
      dp[i].push_back(j);
      wordIndices.push_back(j);
      wordBreak(i + wordDict[j].size(), s, wordDict, result, wordIndices);
      wordIndices.pop_back();
    }
  }
};