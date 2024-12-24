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
    int minimumOperations(TreeNode* root) {
        // count on each level the ones that are on 
        // 3 2 4 1 0    5
        // 0 2 4 1 3
        // 0 1 4 2 3
        // 0 1 2 4 3
        // 0 1 2 3 4
        queue<TreeNode*> queue;
        queue.push(root);
        int count = 0;
        while (queue.size()){
            int size = queue.size();
            vector<int> arr;
            // iterate the tree
            for (int i=0; i<size; i++){
                TreeNode* node = queue.front(); queue.pop();
                arr.push_back(node->val);
                if (node->left) queue.push(node->left); 
                if (node->right) queue.push(node->right); 
            }
            count += count_swaps(arr);
        }
        return count;
    }

private:
    int count_swaps(vector<int>& arr){
        int swaps = 0;
        vector<int> arr_sorted = arr;
        sort(arr_sorted.begin(), arr_sorted.end());
        map<int, int> pos;
        for (int i=0; i<arr_sorted.size(); i++){
            pos[arr[i]] = i;
        }
        for (int i=0; i<arr_sorted.size(); i++){
            if (arr[i] != arr_sorted[i]){
                swaps++;
                pos[arr[i]] = pos[arr_sorted[i]];
                swap(arr[i], arr[pos[arr_sorted[i]]]);
            }
        }
        return swaps;
    }
};