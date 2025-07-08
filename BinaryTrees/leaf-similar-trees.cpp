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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leftLeaves, rightLeaves;
        stack<TreeNode*> leftSt, rightSt;

        leftSt.push(root1);
        while(!leftSt.empty()){
            TreeNode* node = leftSt.top();
            leftSt.pop();
            if(node->left) leftSt.push(node->left);
            if(node->right) leftSt.push(node->right);
            
            if(!node->left && !node->right) leftLeaves.push_back(node->val);
        }

        rightSt.push(root2);
        while(!rightSt.empty()){
            TreeNode* node = rightSt.top();
            rightSt.pop();
            if(node->left) rightSt.push(node->left);
            if(node->right) rightSt.push(node->right);

            if(!node->left && !node->right) rightLeaves.push_back(node->val);
        }
        
        return leftLeaves == rightLeaves;
        
    }
};