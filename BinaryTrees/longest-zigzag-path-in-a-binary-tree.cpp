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
    int longestZigZag(TreeNode* root) {
        if(!root) return 0; 

        int longest = 0;
        // node, direction and count
        stack<tuple<TreeNode*, int, int>> st;
        // Directions:
        // left: 0, right: 1
        if(root->left) st.push({root->left, 0, 1});
        if(root->right) st.push({root->right, 1, 1});

        while(!st.empty()){
            auto[node, direction, length] = st.top();
            st.pop();

            longest = max(longest, length);

            if(node->left) {
                if(direction == 1){
                    st.push({node->left, 0, length+1});
                } else{
                    st.push({node->left, 0, 1});
                }
            }
            if(node->right){
                 if(direction == 0){
                    st.push({node->right, 1, length+1});
                } else{
                    st.push({node->right, 1, 1});
                }
            }
        }

        return longest;
        
    }
};