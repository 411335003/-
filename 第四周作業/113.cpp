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
    vector<int>temp;
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        dfs(root, targetSum);
        return ans;
    }
    void dfs(TreeNode* node, int  targetSum) {
        if(!node)return;
        temp.push_back(node->val);
        targetSum -= node->val; // 剩下的目標值變小了
        if(!node->left && !node->right && targetSum == 0) //如果是葉子，且目標數扣temp裡面的數為0代表找到了
        {
            ans.push_back(temp);
        }
        else //如果不是葉子就繼續往下
        {
            dfs(node->right,targetSum);
            dfs(node->left,targetSum);
        }
        temp.pop_back(); //如果已經是葉子(把可能的答案找過了)，遞迴往左邊找看看
    }
};