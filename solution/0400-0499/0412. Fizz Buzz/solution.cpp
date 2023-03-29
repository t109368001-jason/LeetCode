class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> result(n);
    int            m3 = 3;
    int            m5 = 5;
    int            i  = 1;
    for (string& s : result) {
      bool asNumber = true;
      if (i % 3 == 0) {
        asNumber = false;
        s += "Fizz" + 1;
      }
      if (i % 5 == 0) {
        asNumber = false;
        s += "Buzz";
      }
      if (asNumber) {
        s = to_string(i);
      }
      i++;
    }
    return result;
  }
};