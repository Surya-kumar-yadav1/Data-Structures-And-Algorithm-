/*
Problem: 2265. Count Nodes Equal to Average of Subtree
Difficulty: Medium
Topic: Binary Tree, DFS, Postorder Traversal

Approach:
- For every node, we need the sum and number of nodes in its subtree.
- We use postorder traversal because we first need the information
  from the left and right subtrees.
- For a node:
    total sum = left sum + right sum + node value
    total nodes = left nodes + right nodes + 1

- The average of the subtree is:
    total sum / total nodes

- Since the problem requires rounding down, integer division gives
  the required average.

- If the node value is equal to the average, increment the answer.
- Return the sum and number of nodes of the current subtree.

Time Complexity:
- Every node is visited exactly once.
- Therefore, time complexity is O(n), where n is the number of nodes.

Space Complexity:
- The recursion stack can contain up to the height of the tree.
- Therefore, space complexity is O(h).
- In the worst case of a skewed tree, h = n, so space is O(n).
*/

class Solution {
public:
    int valid = 0;

    pair<int, int> fun(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto [leftSum, leftNodes] = fun(root->left);
        auto [rightSum, rightNodes] = fun(root->right);

        int sum = leftSum + rightSum + root->val;
        int nodes = leftNodes + rightNodes + 1;

        int avg = sum / nodes;

        if (root->val == avg)
            valid++;

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return valid;
    }
};
