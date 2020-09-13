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
    int get_levels(TreeNode *root){
        if(root == NULL) return 0;
        return max(get_levels(root -> left), get_levels(root -> right)) + 1;
    }
    void level_order_traversal(TreeNode *root, int total_levels, vector <vector<int>> &values, int cur_level = 0){
        if(root == NULL) return;
        if(cur_level == total_levels) return;
        values[cur_level].emplace_back(root -> val);
        level_order_traversal(root -> left, total_levels, values, cur_level + 1);
        level_order_traversal(root -> right, total_levels, values, cur_level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int levels = get_levels(root);
        vector<vector<int>> values(levels);
        level_order_traversal(root, levels, values);
        return values;
    }
};