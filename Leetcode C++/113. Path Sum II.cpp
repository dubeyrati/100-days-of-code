class Solution {
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(TreeNode *root, int target) {
        if (!root) return;
        tmp.push_back(root->val);
        target -= root->val;
        if (target == 0 && !root->left && !root->right) ans.push_back(tmp);
        dfs(root->left, target);
        dfs(root->right, target);
        tmp.pop_back();
    }

public:

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};