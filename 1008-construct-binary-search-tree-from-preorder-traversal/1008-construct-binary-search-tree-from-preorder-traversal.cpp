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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> stack{{root}};

    for (int i = 1; i < preorder.size(); ++i) {
      TreeNode* parent = stack.top();
      TreeNode* child = new TreeNode(preorder[i]);
      // Adjust the parent.
      while (!stack.empty() && stack.top()->val < child->val)
        parent = stack.top(), stack.pop();
      // Create parent-child link according to BST property.
      if (parent->val > child->val)
        parent->left = child;
      else
        parent->right = child;
      stack.push(child);
    }

    return root;
  }
};