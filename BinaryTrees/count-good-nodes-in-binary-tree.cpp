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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        int counter = 0;
        while(!st.empty()){
            auto [node, maxSoFar] = st.top();
            st.pop();

            if(node->val >= maxSoFar) counter++;
            int newMax = max(maxSoFar, node->val);

            if(node->left) st.push({node->left, newMax});
            if(node->right) st.push({node->right, newMax});
        }

        return counter;        
    }
};