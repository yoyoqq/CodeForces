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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // parent child isLeft 
        map<int, TreeNode*> tree; // hold parent 
        set<int> children;
        for (auto description : descriptions) {
            int valParent = description[0];
            int valChild = description[1];
            int isLeft = description[2];
            children.insert(valChild);
            // create parent 
            if (tree.count(valParent) == 0) {
                TreeNode* parent = new TreeNode(valParent);
                tree[valParent] = parent;
            }
            // create children 
            if (tree.count(valChild) == 0) {
                TreeNode* child = new TreeNode(valChild);
                tree[valChild] = child;
            }
            if (isLeft) {
                tree[valParent]->left = tree[valChild];
            } else {
                tree[valParent]->right = tree[valChild];
            }
        }
        // return the parent, if parent never in child
        for (auto description : descriptions) {
            int valParent = description[0];
            int valChild = description[1];
            if (children.count(valParent) == 0) return tree[valParent]; 
        }
        return new TreeNode();
    }
};