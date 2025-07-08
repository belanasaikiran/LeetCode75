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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return nullptr;

        if(key > root->val) root->right = deleteNode(root->right, key);
        else if(key < root->val) root->left = deleteNode(root->left, key);
        else {
            if(!root->left && !root->right){
                // delete the curr
                delete root;
                return nullptr;
            } else if (!root->left){
                // only right
                TreeNode* node = root->right;
                delete(root);
                return node;
            } else if(!root->right){
                // only left
                TreeNode* node = root->left;
                delete(root);
                return node;
            } else {
                // has both left and right children
                TreeNode* curr = root->right;
                while(curr->left){
                    curr = curr->left;
                }
                root->val = curr->val; // update the root value with the smallest value in right sub-tree
                root->right = deleteNode(root->right, curr->val);

                
            }
        }

        return root;
        
    }
};