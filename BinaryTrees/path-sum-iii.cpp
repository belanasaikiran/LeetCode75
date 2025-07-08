/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        stack<pair<TreeNode*, vector<int>>> st;
        // instead of int, try adding a pair again to track of what was before summing to current value to remove later.
        st.push({root, {root->val}});

        int answers = 0;
        // found at: 5, found at: 2

        while (!st.empty()) {
            auto [node, path] = st.top();
            st.pop();


            long long sum = 0;
            for(int i = path.size() - 1; i >= 0; i--){
                sum += path[i];
                if(sum == targetSum) answers++;
            }


            if (node->left) {
                vector<int> newPath = path;
                newPath.push_back(node->left->val);
                st.push({node->left, newPath});
            }
            if (node->right) {
                vector<int> newPath = path;
                newPath.push_back(node->right->val);
                st.push({node->right, newPath});
            }
        }

        return answers;
    }
};