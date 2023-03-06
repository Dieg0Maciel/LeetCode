/*
    We perform Breadth-First-Search where the values of the nodes at the same depth are stored together in a vector.
*/

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> result;
        if (!root) {
            return result;
        }
        std::deque<TreeNode*> q;
        q.push_back(root);
        while (q.size() > 0) {
            int qSize = q.size();
            std::vector<int> levelNodes;
            while (qSize > 0) {
                TreeNode* node = q.front();
                q.pop_front();
                qSize--;
                levelNodes.push_back(node->val);
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right) {
                    q.push_back(node->right);
                }
            }
            if (levelNodes.size() > 0) {
                result.push_back(levelNodes);
            }
        }
        return result;
    }
};
