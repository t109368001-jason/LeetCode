class LRUCache {
  size_t m_capacity;
  unordered_map<int, list<pair<int, int>>::iterator>
                       m_map;   // m_map_iter->first: key, m_map_iter->second: list iterator;
  list<pair<int, int>> m_list;  // m_list_iter->first: key, m_list_iter->second: value;
 public:
  LRUCache(size_t capacity) : m_capacity(capacity) {}
  int get(int key) {
    auto found_iter = m_map.find(key);
    if (found_iter == m_map.end())                              // key doesn't exist
      return -1;
    m_list.splice(m_list.begin(), m_list, found_iter->second);  // move the node corresponding to key to front
    return found_iter->second->second;                          // return value of the node
  }
  void put(int key, int value) {
    auto found_iter = m_map.find(key);
    if (found_iter != m_map.end())                                // key exists
    {
      m_list.splice(m_list.begin(), m_list, found_iter->second);  // move the node corresponding to key to front
      found_iter->second->second = value;                         // update value of the node
      return;
    }
    if (m_map.size() == m_capacity)  // reached capacity
    {
      int key_to_del = m_list.back().first;
      m_list.pop_back();               // remove node in list;
      m_map.erase(key_to_del);         // remove key in map
    }
    m_list.emplace_front(key, value);  // create new node in list
    m_map[key] = m_list.begin();       // create correspondence between key and node
  }
};
// first success
class LRUCache1 {
  size_t           p;
  int              capacity;
  map<int, int>    data;
  map<int, size_t> k2p;
  map<size_t, int> p2k;

 public:
  LRUCache1(int capacity) : p(numeric_limits<size_t>::max()), capacity(capacity), data(), k2p(), p2k() {}

  int get(int key) {
    auto it = getIter(key);
    if (it == data.end()) {
      return -1;
    }
    return it->second;
  }

  map<int, int>::iterator getIter(int key) {
    auto it = data.find(key);
    if (it == data.end()) {
      return it;
    }
    auto k2pIt = k2p.find(key);
    p2k.erase(k2pIt->second);

    k2p[key] = p;
    p2k[p]   = key;
    p--;
    return it;
  }

  void put(int key, int value) {
    auto it = getIter(key);
    if (it != data.end()) {
      it->second = value;
      return;
    }
    if (data.size() >= capacity) {
      auto p2kIt = p2k.rbegin();
      data.erase(p2kIt->second);
      k2p.erase(p2kIt->second);
      p2k.erase(p2kIt->first);
    }

    data[key] = value;
    k2p[key]  = p;
    p2k[p]    = key;
    p--;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */