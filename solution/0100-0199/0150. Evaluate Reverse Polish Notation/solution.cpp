class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto& token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int op1 = st.top();
        st.pop();
        int op2 = st.top();
        st.pop();
        switch (token[0]) {
          case '+': op1 = op2 + op1; break;
          case '-': op1 = op2 - op1; break;
          case '*': op1 = op2 * op1; break;
          case '/': op1 = op2 / op1; break;
        }
        st.push(op1);
      } else {
        st.push(stoi(token));
      }
    }
    return st.top();
  }
};