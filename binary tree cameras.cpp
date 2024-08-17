
class Solution
{
public:
    int cameraCount = 0;
    int needCamera = 0;
    int hasCamera = 1;
    int covered = 2;
    int notNeeded = 3;

    int getCameraStatusForEachNode(TreeNode *root)
    {
        if (root == NULL)
            return notNeeded;
        // leaf
        if (root->left == NULL && root->right == NULL)
        {
            return needCamera;
        }
        int leftStatus = getCameraStatusForEachNode(root->left);
        int rightStatus = getCameraStatusForEachNode(root->right);
        if (leftStatus == needCamera || rightStatus == needCamera)
        {
            cameraCount++;
            return hasCamera;
        }
        if (leftStatus == hasCamera || rightStatus == hasCamera)
            return covered;

        return needCamera;
    }
    int minCameraCover(TreeNode *root)
    {
        cameraCount = getCameraStatusForEachNode(root) == needCamera ? cameraCount + 1 : cameraCount;
        return cameraCount;
    }
};