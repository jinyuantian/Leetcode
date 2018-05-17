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
    void recoverTree(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* pre = nullptr;
        helper(root, pre, first, second);
        swap(first -> val, second -> val);
        return;
    }

    void helper(TreeNode* root, TreeNode*&pre, TreeNode*& first,TreeNode*& second){
        if(root == nullptr) return;
        helper(root -> left, pre, first, second);

        if(pre && pre -> val > root -> val){
            if(first == nullptr) first = pre;
            second = root;
        }

        pre = root;

        helper(root -> right, pre, first, second);
    }

};
