class Solution {
public:
    Node* connect(Node* root) {
           if (!root) return root;
        
        // {node, level}
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        auto prev_node = root;
        int prev_level = -1;
        while (!q.empty()) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (prev_level == level) {
                prev_node->next = node;
            }
            
            if (node->left) q.push({node->left, level+1});
            if (node->right) q.push({node->right, level+1});
            prev_node = node;
            prev_level = level;
        }
        
        return root;
    }
};