class Solution {
 public:
  // Kahn's Algorithm 98%/80%
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int                 n = prerequisites.size();
    vector<vector<int>> adj(numCourses);          // Adjacency matrix.
    vector<int>         indegree(numCourses, 0);  // indegree array.

    // traversing all the nodes of the graph.
    for (int i = 0; i < n; i++) {
      // filling adjacency matrix for all the nodes of the graph.
      adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      // also filling indegree value for all nodes.
      indegree[prerequisites[i][0]] += 1;
    }

    vector<int> ans;

    // if graph is DAG and Kahn's algo is applied then return the ans.
    if (kahnAlgo(adj, numCourses, indegree, ans)) return ans;

    // otherwise return the empty vector.
    return {};
  }

  bool kahnAlgo(vector<vector<int>>& adj, int n, vector<int>& indegree, vector<int>& ans) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
      // will push all the nodes with the indegree 0 in the queue as we have completed all the prerequisites for it.
      if (indegree[i] == 0) q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
      // one by one we will take every element of the queue and will traverse the adjacency list of it
      // and will remove that node and will reduce the indegree of the adjacent nodes which are
      // prerequisites for it.
      int curr = q.front();
      q.pop();

      for (auto a : adj[curr]) {
        indegree[a] -= 1;
        // and will push the node having 0 indegree in the queue.
        if (indegree[a] == 0) q.push(a);
      }
      // and after processing current node, will push it in the ans.
      ans.push_back(curr);
      count++;
    }

    // checking for DAG.
    if (count != n) return false;
    return true;
  }

 public:
  // BFS 45%/26%
  vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
    graph       g       = buildGraph(numCourses, prerequisites);
    vector<int> degrees = computeIndegrees(g);
    vector<int> order;
    for (int i = 0; i < numCourses; i++) {
      int j = 0;
      for (; j < numCourses; j++) {
        if (!degrees[j]) {
          order.push_back(j);
          break;
        }
      }
      if (j == numCourses) {
        return {};
      }
      degrees[j]--;
      for (int v : g[j]) {
        degrees[v]--;
      }
    }
    return order;
  }

 private:
  typedef vector<vector<int>> graph;

  graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
    graph g(numCourses);
    for (auto p : prerequisites) {
      g[p[1]].push_back(p[0]);
    }
    return g;
  }

  vector<int> computeIndegrees(graph& g) {
    vector<int> degrees(g.size(), 0);
    for (auto adj : g) {
      for (int v : adj) {
        degrees[v]++;
      }
    }
    return degrees;
  }

 public:
  // first success 87%/5.85%
  vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>>          reqMap;
    unordered_map<int, vector<vector<int>*>> iReqMap;
    for (int i = 0; i < numCourses; i++) {
      reqMap[i];
    }
    for (vector<int>& pair : prerequisites) {
      auto& v = reqMap[pair[0]];
      v.push_back(pair[1]);
      iReqMap[pair[1]].push_back(&v);
    }

    vector<int> result;
    stack<int>  st;
    set<int>    s;
    auto        it = reqMap.begin();
    while (!reqMap.empty()) {
      // cout << "A " << it->first << endl;
      if (it == reqMap.end()) {
        if (!st.empty()) {
          it = reqMap.find(st.top());
          s.erase(st.top());
          st.pop();
          // cout << "B " << it->first << endl;
        } else {
          it = reqMap.begin();
          // cout << "C " << it->first << endl;
        }
      }
      if (s.contains(it->first)) {
        return {};
      }
      if (!it->second.empty()) {
        st.push(it->first);
        s.insert(it->first);
        it = reqMap.find(it->second[0]);
        // cout << "D " << it->first << endl;
      } else {
        // cout << "E " << it->first << endl;
        result.push_back(it->first);
        for (vector<int>* v : iReqMap[it->first]) {
          v->erase(std::remove(v->begin(), v->end(), it->first), v->end());
        }
        iReqMap.erase(it->first);
        reqMap.erase(it);
        it = reqMap.end();
      }
    }
    return result;
  }
};