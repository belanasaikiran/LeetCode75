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
    int maxLevelSum(TreeNode* root) {
        int maxSumLevel = 1;
        int Level = 1;
        int maxSum = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            while(size > 0){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
            if(sum > maxSum){
                maxSum = sum; 
                maxSumLevel = Level;
            }
            Level++;
        }
        return maxSumLevel;
    }
};