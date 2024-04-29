/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;
    deque<TreeNode*> dq{{root}};
    bool isLeftToRight = true;

    while (!dq.empty()) {
      vector<int> currLevel;
      for (int sz = dq.size(); sz > 0; --sz)
        if (isLeftToRight) {
          TreeNode* node = dq.front();
          dq.pop_front();
          currLevel.push_back(node->val);
          if (node->left)
            dq.push_back(node->left);
          if (node->right)
            dq.push_back(node->right);
        } else {
          TreeNode* node = dq.back();
          dq.pop_back();
          currLevel.push_back(node->val);
          if (node->right)
            dq.push_front(node->right);
          if (node->left)
            dq.push_front(node->left);
        }
      ans.push_back(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};