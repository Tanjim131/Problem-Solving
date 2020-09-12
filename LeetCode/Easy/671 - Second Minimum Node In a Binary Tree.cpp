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
    long long iterate(TreeNode *root, long long smallest = numeric_limits <long long>::max(), long long second_smallest = -1){
        if(root == NULL) return second_smallest;
        if(smallest > root -> val){
            second_smallest = smallest;
            smallest = root -> val;
        } else if(smallest < root -> val){
            second_smallest = min(second_smallest, 1LL * root -> val);
        }
        long long L = iterate(root -> left, smallest, second_smallest);
        long long R = iterate(root -> right, smallest, second_smallest);
        return min(L, R);
    }
    int findSecondMinimumValue(TreeNode* root) {
        long long second_minimum = iterate(root);
        return second_minimum == numeric_limits<long long>::max() ? -1 : second_minimum;
    }
};