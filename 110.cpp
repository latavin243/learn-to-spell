/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return getHeightAndIsBalanced(root, height);
    }

    bool getHeightAndIsBalanced(TreeNode* t, int& height) {
        if (!t) {
            height = 0;
            return true;
        }

        int leftHeight, rightHeight;
        bool leftBalanced = getHeightAndIsBalanced(t->left, leftHeight);
        if (!leftBalanced) return false;
        bool rightBalanced = getHeightAndIsBalanced(t->right, rightHeight);
        if (!rightBalanced) return false;

        if (abs(leftHeight - rightHeight) > 1) return false;

        // balanced
        height = max(leftHeight, rightHeight) + 1;
        return true;
    }
};