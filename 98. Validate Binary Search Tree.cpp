/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, (long)INT_MIN, (long)INT_MAX);
    }

    bool helper(TreeNode* root, long lowerbound, long upperbound){
        if(root == nullptr) return true;
        if( (long)(root -> val) > upperbound || (long)(root -> val) < lowerbound )
            return false;
        return helper(root -> left, lowerbound, (long)(root -> val) - 1) &&
            helper(root -> right, (long)(root -> val) + 1, upperbound);
    }
};
