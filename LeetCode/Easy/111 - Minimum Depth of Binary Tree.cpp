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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root -> left == nullptr && root -> right == nullptr) return 1;
        int left = numeric_limits<int>::max(), right = numeric_limits<int>::max();
        if(root -> left != nullptr) left = minDepth(root -> left);
        if(root -> right != nullptr) right = minDepth(root -> right);
        return 1 + min(left, right);
    }
};

/*****************************************************************************************/

class Solution {
public:
    void min_depth_util(TreeNode *root, int &min_depth, int depth = 1){
        if(root -> left == nullptr && root -> right == nullptr){
            min_depth = min(min_depth, depth);
            return;
        }
        if(depth >= min_depth) return;
        if(root -> left != nullptr) min_depth_util(root -> left, min_depth, depth + 1);
        if(root -> right != nullptr) min_depth_util(root -> right, min_depth, depth + 1);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int min_depth = numeric_limits<int>::max();
        min_depth_util(root, min_depth);
        return min_depth;
    }
};

/*****************************************************************************************/

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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue <TreeNode*> q;
        map <TreeNode*, int> depths;
        q.push(root);
        depths[root] = 1;
        int depth = -1;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left == nullptr && current -> right == nullptr){
                depth = depths[current];
                break;
            }
            if(current -> left != nullptr){
                q.push(current -> left);
                depths[current -> left] = depths[current] + 1;
            }
            if(current -> right != nullptr){
                q.push(current -> right);
                depths[current -> right] = depths[current] + 1;
            }
        }
        return depth;
    }
};