class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) {
      return 0;
    }
    vector<int> lessFromLeft(n);   // idx of the first bar the left that is lower than current
    vector<int> lessFromRight(n);  // idx of the first bar the right that is lower than current
    lessFromRight[n - 1] = n;
    lessFromLeft[0]      = -1;

    for (int i = 1; i < n; i++) {
      int p = i - 1;

      while (p >= 0 && heights[p] >= heights[i]) {
        p = lessFromLeft[p];
      }
      lessFromLeft[i] = p;
    }

    for (int i = n - 2; i >= 0; i--) {
      int p = i + 1;

      while (p < n && heights[p] >= heights[i]) {
        p = lessFromRight[p];
      }
      lessFromRight[i] = p;
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
    }

    return maxArea;
  }
  // TLE
  int largestRectangleArea2(vector<int>& heights) {
    int maxArea = INT_MIN;
    largestRectangleArea2(0, heights.size(), heights, maxArea);
    return maxArea;
  }
  void largestRectangleArea2(int beg, int end, vector<int>& heights, int& maxArea) {
    if (beg == end) {
      maxArea = max(maxArea, heights[beg]);
      return;
    }
    int minIndex;
    int minHeight = INT_MAX;
    int maxHeight = INT_MIN;
    for (int i = beg; i < end; i++) {
      int height = heights[i];
      if (height < minHeight) {
        minIndex  = i;
        minHeight = height;
      }
      maxHeight = max(maxHeight, height);
    }
    int area = minHeight * (end - beg);
    if (area > maxArea) {
      maxArea = area;
    }
    if (maxHeight * (end - minIndex) > maxArea) {
      largestRectangleArea2(minIndex + 1, end, heights, maxArea);
    }
    if (maxHeight * (minIndex - beg) > maxArea) {
      largestRectangleArea2(beg, minIndex, heights, maxArea);
    }
  }

  // TLE
  int largestRectangleArea1(vector<int>& heights) {
    int minHeight = INT_MAX;
    int maxHeight = INT_MIN;
    for (int height : heights) {
      minHeight = min(minHeight, height);
      maxHeight = max(maxHeight, height);
    }
    int                     maxArea = minHeight * heights.size();
    unordered_map<int, int> dp;
    for (int i = 0; i < heights.size(); i++) {
      int height = heights[i];
      if (height == minHeight) {
        dp = unordered_map<int, int>();
        continue;
      }
      dp[i]   = height;
      maxArea = max(maxArea, height);
      for (auto& [j, h] : dp) {
        h = min(height, h);
        // cout << "i=" << i << ", j=" << j << ", h=" << h << ", l=" << (i-j+1) << endl;
        int area = h * (i - j + 1);
        maxArea  = max(maxArea, area);
      }
    }
    return maxArea;
  }
};