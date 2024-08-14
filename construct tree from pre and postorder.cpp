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
class Solution
{
public:
    TreeNode *con(vector<int> &preorder, vector<int> &postorder, int pres, int pree, int posts, int poste)

    {
        if (pres > pree)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pres]);

        if (pres == pree)
            return root;

        int idx = posts;

        while (postorder[idx] != preorder[pres + 1])
            idx++;

        int size = idx - posts + 1;

        root->left = con(preorder, postorder, pres + 1, pres + size, posts, idx);
        root->right = con(preorder, postorder, pres + size + 1, pree, idx + 1, poste);

        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {

        return con(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};