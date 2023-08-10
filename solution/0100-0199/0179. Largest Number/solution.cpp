class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> numStrs;
    for (auto num : nums) {
      numStrs.push_back(to_string(num));
    }
    sort(numStrs.begin(), numStrs.end(), [](auto s1, auto s2) { return s1 + s2 > s2 + s1; });
    string result;
    for (auto numStr : numStrs) {
      result += numStr;
    }
    return result[0] == '0' ? "0" : result;
  }
};