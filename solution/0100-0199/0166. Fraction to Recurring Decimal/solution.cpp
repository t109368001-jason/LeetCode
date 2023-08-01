class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    string result;
    if (numerator == 0) {
      return "0";
    }
    if (denominator == 1) {
      return to_string(numerator);
    }
    if (denominator == -1) {
      return to_string(labs(numerator));
    }
    if (numerator > 0 ^ denominator > 0) {
      result += '-';
    }
    long num = labs(numerator);
    long d   = labs(denominator);
    if (num > d) {
      int q = num / d;
      result += to_string(q);
      num -= q * d;
    } else {
      result += "0";
    }
    if (num == 0) {
      return result;
    }
    result += ".";
    unordered_map<int, size_t> numMap;
    while (num != 0) {
      auto it = numMap.find(num);
      if (it != numMap.end()) {
        result += ")";
        result.insert(it->second, "(");
        break;
      }
      numMap[num] = result.size();
      num *= 10;
      if (num > d) {
        int q = num / d;
        result += to_string(q);
        num -= q * d;
      } else {
        result += "0";
      }
    }
    return result;
  }
};