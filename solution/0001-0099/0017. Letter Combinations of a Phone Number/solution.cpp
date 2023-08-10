// 20230329
class Solution {
  vector<string> table = {
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz",  // 9
  };

 public:
  // recursive 100%/69%
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> result;
    string         prefix;
    letterCombinations(0, digits, prefix, result);
    return result;
  }

  void letterCombinations(int index, string digits, string prefix, vector<string>& result) {
    if (index >= digits.size()) {
      result.push_back(prefix);
      return;
    }
    auto wordList = table[digits[index] - '2'];
    for (char word : wordList) {
      prefix.push_back(word);
      letterCombinations(index + 1, digits, prefix, result);
      prefix.pop_back();
    }
  }
  vector<string> letterCombinations2(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> result;
    result.push_back("");
    for (char digit : digits) {
      vector<string> tmp;
      for (char c : table[digit - '2']) {
        for (auto s : result) {
          tmp.push_back(s + c);
        }
      }
      swap(result, tmp);
    }
    return result;
  }
  // recursive 100%/22%
  vector<string> letterCombinations1(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> result;
    letterCombinations1(digits, "", result);
    return result;
  }

  void letterCombinations1(string digits, string prefix, vector<string>& result) {
    if (digits.empty()) {
      result.push_back(prefix);
      return;
    }
    auto wordList = table[digits[0] - '2'];
    for (char word : wordList) {
      string remainDigits = digits.substr(1);
      letterCombinations1(remainDigits, prefix + word, result);
    }
  }
};