
class Solution {
public:
   int maxSum;
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        maxGain(root);
        return maxSum;
    }
    int maxGain(TreeNode* root){
        if(root==NULL)
            return 0;
        int ls=max(maxGain(root->left),0);
        int rs=max(maxGain(root->right),0);
        int sum=ls+rs+root->val;
        maxSum=max(maxSum,sum);
        return root->val+max(ls,rs);
    }
};