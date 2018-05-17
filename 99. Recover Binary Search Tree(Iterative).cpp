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
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur -> left;
            }
            else{
                cur = s.top();
                s.pop();
                if(pre && pre -> val > cur -> val){
                    if(first == nullptr)
                        first = pre;
                    second = cur;
                }

                pre = cur;
                cur = cur -> right;
            }
        }
        swap(first -> val, second -> val);
        return;
    }
};
