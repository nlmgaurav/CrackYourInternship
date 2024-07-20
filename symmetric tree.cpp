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
bool same(TreeNode* l,TreeNode* r)
{
    if(!l && !r)return true;
    if(!l || !r)return false;
    return l->val==r->val && same(l->left,r->right) && same(l->right,r->left);
}
    bool isSymmetric(TreeNode* root) {
        return same(root,root);
    }
};