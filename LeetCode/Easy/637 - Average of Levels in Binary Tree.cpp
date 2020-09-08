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

struct Info{
    long long sum;
    int count;
};

class Solution {
public:
    int getLevels(TreeNode *root){
        if(root == NULL) return 0;
        return 1 + max(getLevels(root -> left), getLevels(root -> right));
    }
    void getInfo(TreeNode *root, int tL, vector<Info> &info, int cL = 0){
        if(root == NULL) return;
        if(cL == tL) return;
        info[cL].sum += root -> val;
        ++info[cL].count;
        getInfo(root -> left, tL, info, cL + 1);
        getInfo(root -> right, tL, info, cL + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int levels = getLevels(root);
        vector <Info> info(levels); // info[0] --> sum, info[1] --> count
        getInfo(root, levels, info);
        vector <double> average(levels);
        for(int i = 0 ; i < levels ; ++i){
            average[i] = info[i].sum * 1.0 / info[i].count;
        }
        return average;
    }
};