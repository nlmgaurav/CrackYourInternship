Node *lca(Node *root, int a, int b)
{
    if (!root || root->data == a || root->data == b)
        return root;

    Node *l = lca(root->left, a, b), *r = lca(root->right, a, b);
    if (l && r)
        return root;
    return l ? l : r;
}
int dist(Node *lca, int target)
{
    if (!lca)
        return 1e5;
    if (lca->data == target)
        return 0;
    return 1 + min(dist(lca->left, target), dist(lca->right, target));
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *lc = lca(root, a, b);
    return dist(lc, a) + dist(lc, b);
}