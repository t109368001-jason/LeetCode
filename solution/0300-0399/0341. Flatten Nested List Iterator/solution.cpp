/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  stack<vector<NestedInteger>::iterator> begins, ends;

 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    begins.push(nestedList.begin());
    ends.push(nestedList.end());
  }

  int next() {
    hasNext();
    return (begins.top()++)->getInteger();
  }

  bool hasNext() {
    while (begins.size()) {
      if (begins.top() == ends.top()) {
        begins.pop();
        ends.pop();
      } else {
        auto x = begins.top();
        if (x->isInteger()) return true;
        begins.top()++;
        begins.push(x->getList().begin());
        ends.push(x->getList().end());
      }
    }
    return false;
  }
};

// first success 84%/79%
class NestedIterator1 {
  vector<NestedInteger>&        nestedList;
  stack<vector<NestedInteger>*> nestedListSt;
  stack<size_t>                 iSt;

 public:
  NestedIterator1(vector<NestedInteger>& nestedList) : nestedList(nestedList) {
    nestedListSt.push(&nestedList);
    iSt.push(-1);
    _next();
  }

  int next() {
    cout << "next" << endl;
    int result = (*nestedListSt.top())[iSt.top()].getInteger();
    _next();
    return result;
  }

  void _next() {
    NestedInteger* nip;
    while (!nestedListSt.empty()) {
      auto    nlp = nestedListSt.top();
      size_t& i   = iSt.top();
      if (++i < nlp->size()) {
        cout << i << nlp->size() << endl;
        nip       = &((*nlp)[i]);
        bool flag = false;
        while (!nip->isInteger()) {
          nestedListSt.push(&nip->getList());
          iSt.push(0);
          if (nip->getList().empty()) {
            flag = true;
            break;
          }
          nip = &nip->getList()[0];
        }
        if (flag) {
          continue;
        }
        break;
      } else {
        nestedListSt.pop();
        iSt.pop();
      }
    }
  }

  bool hasNext() { return !nestedListSt.empty(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */