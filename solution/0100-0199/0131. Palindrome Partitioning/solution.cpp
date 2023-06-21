class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string>         tmp;
    partitionRecursive(0, s, tmp, result);
    return result;
  }

  void partitionRecursive(int index, string& s, vector<string>& current, vector<vector<string>>& result) {
    if (index >= s.size()) {
      result.push_back(current);
      return;
    }
    for (int i = index; i < s.size(); i++) {
      if (isPalindrome(s, index, i)) {
        current.push_back(s.substr(index, i - index + 1));
        partitionRecursive(i + 1, s, current, result);
        current.pop_back();
      }
    }
  }

  bool isPalindrome(string& s, int l, int r) {
    for (; l < r; l++, r--) {
      if (s[l] != s[r]) {
        return false;
      }
    }
    return true;
  }
};