class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    const int n = nums.size();
    if (n < 3) return -1;

    int ans = INT_MAX;

    vector<int> minPrefix(n, INT_MAX);
    vector<int> minSuffix(n, INT_MAX);

    minPrefix[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      minPrefix[i] = min(minPrefix[i - 1], nums[i]);
    }


    minSuffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      minSuffix[i] = min(minSuffix[i + 1], nums[i]);
    }

    for (int i = 1; i < n - 1; ++i) {
      if (nums[i] > minPrefix[i - 1] && nums[i] > minSuffix[i + 1]) {
        ans = min(ans, nums[i] + minPrefix[i - 1] + minSuffix[i + 1]);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
