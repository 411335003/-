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
    int maxDepth = 0;
    int totalSum = 0;

    int deepestLeavesSum(TreeNode* root) {
        // 開始遞迴，初始深度設為 0
        dfs(root, 0);
        return totalSum;
    };

    void dfs(TreeNode* node, int depth) {
        if (!node) return; // 安全檢查：如果節點不存在就跳出

        // 判斷是否為葉子節點 (左右都沒有子節點)
        if (!node->left && !node->right) {
            if (depth > maxDepth) {
                // 發現了更深的一層！重置最大深度與總和
                maxDepth = depth;
                totalSum = node->val;
            } else if (depth == maxDepth) {
                // 又是目前最深的那一層，把值加進去
                totalSum += node->val;
            }
        }

        // 繼續往左右探測，深度 + 1
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    };
};
