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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int preIdx = 0, postIdx = 0;
            return dfs(preorder, postorder, preIdx, postIdx);
        }
    
    private:
        TreeNode* dfs(vector<int>& preorder, vector<int>& postorder, int& preIdx, int& postIdx){
            TreeNode* node = new TreeNode(preorder[preIdx++]);
    
            // base case
            if (node->val == postorder[postIdx]){
                postIdx++;
                return node;
            }
            // children
            if (preIdx < preorder.size() && node->val != postorder[postIdx]){
                node->left = dfs(preorder, postorder, preIdx, postIdx);
            }
            if (preIdx < preorder.size() && node->val != postorder[postIdx]){
                node->right = dfs(preorder, postorder, preIdx, postIdx);
            }
            postIdx++;
            return node; 
        }
    
    };
    
    
    // /**
    //  * Definition for a binary tree node.
    //  * struct TreeNode {
    //  *     int val;
    //  *     TreeNode *left;
    //  *     TreeNode *right;
    //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //  * };
    //  */
    // class Solution {
    // public:
    //     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    //         int preIdx = 1, postIdx = 0;
    //         TreeNode* node = new TreeNode(preorder[0]);
    //         dfs(preorder, postorder, node, preIdx, postIdx);
    //         return node;
    //     }
    
    // private:
    //     set<int> seen;
        
    //     TreeNode* dfs(vector<int>& preorder, vector<int>& postorder, TreeNode* node, int& preIdx, int& postIdx){
    //         // base case
    //         if (preIdx >= preorder.size() || postIdx == postorder.size()) return;
    //         if (seen.find(preorder[preIdx]) != seen.end()) return;
    //         // go as most left as we can if doesnt match
    //         if (preorder[preIdx] == postorder[postIdx] && preIdx < preorder.size()){
    //             node->left = new TreeNode(preorder[preIdx]);
    //             node->right = new TreeNode(postorder[postIdx+1]);
    //             seen.insert(preorder[preIdx]);
    //             seen.insert(postorder[postIdx]);
    //             postIdx += 3;
    //             preIdx += 2;
    //         }
    //         else if (preorder[preIdx] != postorder[postIdx]){
    //             TreeNode* next_node = new TreeNode(preorder[preIdx]);
    //             seen.insert(preorder[preIdx]);
    //             node->left = next_node;
    //             preIdx++;
    //             dfs(preorder, postorder, node->left, preIdx, postIdx);
    //             if (preIdx >= preorder.size() || postIdx == postorder.size()) return;
    //             node->right = new TreeNode(preorder[preIdx]);
    //             seen.insert(preorder[preIdx]);
    //             preIdx++;
    //             dfs(preorder, postorder, node->right, preIdx, postIdx);
    //         }
    //     }
    // };