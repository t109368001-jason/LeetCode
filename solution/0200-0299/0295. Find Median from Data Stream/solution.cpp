class MedianFinder {
  priority_queue<int, std::vector<int>, std::greater<int>> small;
  priority_queue<int>                                      large;

 public:
  MedianFinder() {}

  void addNum(int num) {
    small.push(num);
    large.push(small.top());
    small.pop();
    while (small.size() < large.size()) {
      small.push(large.top());
      large.pop();
    }
  }

  double findMedian() { return small.size() > large.size() ? small.top() : (double)(small.top() + large.top()) / 2.0; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */