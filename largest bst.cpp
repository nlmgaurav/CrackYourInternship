class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    int sizeBST(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return (1 + sizeBST(root->left) + sizeBST(root->right));
        }
    }
    // it returns the given bst in inorder(sorted order)
    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    // this is for to check whther the tree is bst or not
    bool isBST(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        vector<int> v;
        inorder(root, v);

        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] >= v[i + 1])
            {
                return false;
            }
        }

        return true;
    }
    int largestBst(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }

        if (isBST(root) == true)
        {
            return sizeBST(root);
        }
        else
        {
            return max(largestBst(root->left), largestBst(root->right));
        }
    }
};