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
    int count = 0;
    unordered_map<long, int> mp;
    void DFS(TreeNode *root, int targetSum, long sum)
    {
        if (root == NULL)
            return;
        sum += root->val;
        if (sum == targetSum)
            count++;
        if (mp.find(sum - targetSum) != mp.end())
            count += mp[sum - targetSum];
        mp[sum]++;
        DFS(root->left, targetSum, sum);
        DFS(root->right, targetSum, sum);
        mp[sum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        DFS(root, targetSum, 0);
        return count;
    }
};