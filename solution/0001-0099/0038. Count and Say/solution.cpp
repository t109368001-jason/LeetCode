class Solution {
 public:
  string countAndSay(int n) {
    int    current = 2;
    string result  = "11";
    while (current < n) {
      char   target = result[0];
      int    count  = 0;
      string tmp;
      for (int i = 0; i < result.size(); i++) {
        if (result[i] == target) {
          count++;
          continue;
        }
        tmp += to_string(count) + target;
        target = result[i];
        count  = 1;
      }
      tmp += to_string(count) + target;
      result = tmp;
      current++;
    }
    return result;
  }
};