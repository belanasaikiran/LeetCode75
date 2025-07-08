/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // using parent map.
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> qNodes;
        parent[root] = nullptr;
        qNodes.push(root);

        // using BFS to fill parent map
        while(!parent.count(p) || !parent.count(q)){
            TreeNode* node = qNodes.front();
            qNodes.pop();
            if(node->left){
                parent[node->left] = node;
                qNodes.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                qNodes.push(node->right);
            }
        }

        // adding all the ancestors of p to a set
        unordered_set<TreeNode*> ancestors;
        while(p){
            ancestors.insert(p);
            p = parent[p];
        }

        // find first ancetor of q that is in p's ancestor set
        while(!ancestors.count(q)){
            q = parent[q];
        }

        return q;

    }
};