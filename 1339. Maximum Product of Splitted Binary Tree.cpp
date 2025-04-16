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

struct TreeNode*{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        int maxProduct(TreeNode* root) {
            // dfs for left and right
            // get max 
            total = dfs(root);
            dfs(root);
            return mx % mod;
        }
    
    private:
        const int mod = 1e9 + 7;
        long long mx = 0;
        long long total = 0;
    
        long long dfs(TreeNode* node){
            if (!node) return 0;
            // recursion 
            long long cur = node->val + dfs(node->left) + dfs(node->right);
            // calc 
            mx = max(mx, cur * (total - cur));
            return cur;
        }
    
        // long long sum_nodes(TreeNode* node){
        //     if (!node) return 0;
        //     // dfs part 
        //     long long cur = node->val;
        //     long long left = 0, right = 0;
        //     if (node->left) left += sum_nodes(node->left);
        //     if (node->right) right += sum_nodes(node->right);
        //     return cur + left + right;
        // }
    };