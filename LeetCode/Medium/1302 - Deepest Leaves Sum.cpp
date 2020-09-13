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
    int get_height(TreeNode *root){
        if(root == NULL) return -1;
        return max(get_height(root -> left), get_height(root -> right)) + 1;
    }
    int get_sum(TreeNode *root, int height){
        if(root == NULL) return 0;
        if(!height) return root -> val;
        return get_sum(root -> left, height - 1) + get_sum(root -> right, height - 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = get_height(root);
        return get_sum(root, height);
    }
};