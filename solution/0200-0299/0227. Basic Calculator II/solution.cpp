class Solution {
 public:
  int calculate(string s) {
    istringstream in('+' + s + '+');
    int           total = 0;
    int           term  = 0;
    int           n;
    char          op;
    while (in >> op) {
      if (op == '+' || op == '-') {
        total += term;
        in >> term;
        term *= 44 - op;  // '+':43, '-':45
      } else {
        in >> n;
        if (op == '*') {
          term *= n;
        } else {
          term /= n;
        }
      }
    }
    return total;
  }
};