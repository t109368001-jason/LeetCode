class Solution {
 public:
  int splitNum(int num) {
    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }
    sort(digits.begin(), digits.end(), std::greater<int>());
    int num1 = 0;
    int num2 = 0;
    int i    = 0;
    int n    = digits.size();
    while (!digits.empty()) {
      num1 *= 10;
      num1 += digits.back();
      digits.pop_back();
      if (digits.empty()) {
        break;
      }
      num2 *= 10;
      num2 += digits.back();
      digits.pop_back();
    }
    return num1 + num2;
  }
};