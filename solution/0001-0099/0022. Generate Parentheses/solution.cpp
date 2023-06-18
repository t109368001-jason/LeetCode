class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisRecursive(n, 0, "", result);
    return result;
  }

  void generateParenthesisRecursive(int n, int lCount, string s, vector<string>& result) {
    if (n == 0 && lCount == 0) {
      result.push_back(s);
      return;
    }
    if (n > 0) {
      generateParenthesisRecursive(n - 1, lCount + 1, s + "(", result);
    }
    if (lCount > 0) {
      generateParenthesisRecursive(n, lCount - 1, s + ")", result);
    }
  }
};