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
        TreeNode* recoverFromPreorder(string traversal) {
            // process string 
            // vector<pair<int, int>> preorder;
            vector<vector<int>> preorder;
            int dash = 0;
            int i = 0;
            for (; i<traversal.size(); i++){
                if (traversal[i] != '-'){
                    int num = 0;
                    while (i<traversal.size() && traversal[i] != '-'){
                        num = num * 10 + traversal[i] -'0';
                        i++;
                    }
                    preorder.push_back({dash, num});
                    dash = 1;
                }else{
                    dash++;
                }
            }
            // for (int i=0; i<preorder.size(); i++){
            //     cout << preorder[i][0] << " " << preorder[i][1] << endl;
            // }
            // iterate preorder dfs 
            TreeNode* node = new TreeNode(preorder[0][1]);
            int idx = 1;
            dfs(preorder, idx, node, 1);
            return node;
        }
    
    private:
        void dfs(vector<vector<int>>& preorder, int& idx, TreeNode* node, int depth){
            // base case 
            if (idx >= preorder.size()) return;
            // children 
            // left if depth == depthCur
            if (preorder[idx][0] == depth){
                TreeNode* next_node = new TreeNode(preorder[idx][1]);
                node->left = next_node;
                idx++;
                dfs(preorder, idx, node->left, depth+1);
            }
            if (idx >= preorder.size()) return;
            // right if same depth again 
            if (preorder[idx][0] == depth){
                TreeNode* next_node = new TreeNode(preorder[idx][1]);
                node->right = next_node;
                idx++;
                dfs(preorder, idx, node->right, depth+1);
            }
        }
    };