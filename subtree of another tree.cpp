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
    //O(N)
    //sc=O(N)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string tree1,tree2;
        buildPreorder(root,tree1);
        buildPreorder(subRoot,tree2);
        if(tree1.find(tree2)==-1)return false;
        return true;
        
    }
    string buildPreorder(TreeNode* root,string &s)
    {
        if(root==NULL)s+=",#";
        else{
            s+=","+to_string(root->val);
            buildPreorder(root->left,s);
            buildPreorder(root->right,s);
        }
        return s;
    }
};