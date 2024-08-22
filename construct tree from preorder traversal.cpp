

/*Structure of the Node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node *solve(int pre[], char preLN[], int n, int &i)
{
    if (i > n)
    {
        return NULL;
    }
    if (preLN[i] == 'L')
    {
        return new Node(pre[i++]);
    }
    Node *root = new Node(pre[i++]);
    root->left = solve(pre, preLN, n, i);
    root->right = solve(pre, preLN, n, i);
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i = 0;
    return solve(pre, preLN, n, i);
}