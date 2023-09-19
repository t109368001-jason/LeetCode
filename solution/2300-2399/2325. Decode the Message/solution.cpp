class Solution {
 public:
  string decodeMessage(string key, string message) {
    vector<char> dict(26);
    char         curr = 'a';
    for (auto c : key) {
      if (c < 'a' || c > 'z') {
        continue;
      }
      if (dict[c - 'a'] != 0) {
        continue;
      }
      dict[c - 'a'] = curr;
      curr++;
    }
    string result;
    transform(message.begin(), message.end(), back_inserter(result), [&dict](char c) {
      if (c < 'a' || c > 'z') {
        return c;
      }
      return dict[c - 'a'];
    });
    return result;
  }
};