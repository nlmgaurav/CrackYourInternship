vector<float> arr;
void inorder(Node* root) 
{
    if (!root) 
        return;
    
    inorder(root->left);
    arr.push_back(root->data);
    inorder(root->right);
}

float findMedian(struct Node* root) 
{
    
    arr.clear();
    inorder(root);
    int n = arr.size();
    
    if (n % 2==1)
        return arr[n/2];
    else
        return (arr[n/2 - 1] + arr[n/2])/2;
}