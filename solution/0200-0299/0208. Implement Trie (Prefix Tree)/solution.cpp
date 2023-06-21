class TrieNode {
 public:
  TrieNode* child[26];
  bool      isWord;
  TrieNode() {
    isWord = false;
    for (auto& a : child) a = nullptr;
  }
};
class Trie {
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }
  void insert(string s) {
    TrieNode* p = root;
    for (auto& a : s) {
      int i = a - 'a';
      if (!p->child[i]) p->child[i] = new TrieNode();
      p = p->child[i];
    }
    p->isWord = true;
  }
  bool search(string key, bool prefix = false) {
    TrieNode* p = root;
    for (auto& a : key) {
      int i = a - 'a';
      if (!p->child[i]) return false;
      p = p->child[i];
    }
    if (prefix == false) return p->isWord;
    return true;
  }
  bool startsWith(string prefix) { return search(prefix, true); }
};

// first success
class Trie1 {
  using Ptr = Trie1*;

  unordered_map<char, Trie1::Ptr> root;

 public:
  Trie1() : root() {}

  void insert(string word) {
    if (word.empty()) {
      root['\0'] = nullptr;
      return;
    }
    Trie1::Ptr& p = root[word[0]];
    if (!p) {
      p = new Trie1();
    }
    p->insert(word.substr(1));
  }

  bool search(string word) {
    if (word.empty()) {
      return root.find('\0') != root.end();
    }
    auto it = root.find(word[0]);
    if (it == root.end()) {
      return false;
    }
    return it->second->search(word.substr(1));
  }

  bool startsWith(string prefix) {
    auto it = root.find(prefix[0]);
    if (it == root.end()) {
      return false;
    }
    if (prefix.size() == 1) {
      return true;
    }
    return it->second->startsWith(prefix.substr(1));
  }

  ~Trie1() {
    for (auto& [k, v] : root) {
      if (v) {
        delete v;
      }
    }
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */