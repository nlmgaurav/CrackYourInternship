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
void help(TreeNode* root,vector<string>&ans,string cur)
{
    if(!root)return;
    if(!root->left && !root->right)ans.push_back(cur);
    if(root->left)help(root->left,ans,cur+"->"+to_string(root->left->val));
      if(root->right)help(root->right,ans,cur+"->"+to_string(root->right->val));
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root)return ans;
        help(root,ans,to_string(root->val));
        return ans;

    }
};