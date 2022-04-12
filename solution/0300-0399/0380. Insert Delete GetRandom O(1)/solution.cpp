class RandomizedSet {
 protected:
  std::map<int, int> map_;

 public:
  RandomizedSet() : map_() {}

  bool insert(int val) {
    auto result = map_.insert_or_assign(val, val);
    return result.second;
  }

  bool remove(int val) {
    auto nh = map_.extract(val);
    return !nh.empty();
  }

  int getRandom() {
    int  r  = std::rand() % map_.size();
    auto it = map_.begin();
    for (int i = 0; i < r; i++) { it++; }
    return it->second;
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */