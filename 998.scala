/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def insertIntoMaxTree(root: TreeNode, v: Int): TreeNode = {
        if (root == null) return TreeNode(v, null, null)
        if (v > root.value) return TreeNode(v, root, null)
        insertIntoSubTree(root, v)
        root
    }

    def insertIntoSubTree(parent: TreeNode, v: Int): Unit = {
        if (parent.right == null || v > parent.right.value) {
            parent.right = TreeNode(v, parent.right, null)
            return
        }
        insertIntoSubTree(parent.right, v)
    }
}