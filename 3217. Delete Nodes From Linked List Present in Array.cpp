/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> seen(nums.begin(), nums.end());

        // head is valid 
        while (head != nullptr && seen.count(head->val) > 0){
            ListNode* temp = head;
            head = head->next;
            // delete temp;
        }
        if (head == nullptr) return head;

        // iterate 
        ListNode* cur = head;
        while (cur->next != nullptr){
            // skip this one 
            if (seen.contains(cur->next->val)){
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                // delete temp;
            }
            // good 
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         // how to do in O(1) memory, skip the nodes that are in nums 
        
//         // use set for nums 
//         set<int> seen; 
//         for(int& x : nums) seen.insert(x);
//         // find initial position that head works 
//         while (head != nullptr && seen.find(head->val) != seen.end()){
//             head = head->next;
//         }
//         // from current position, point next if not in seen
//         ListNode* left = head;
//         ListNode* right = head->next;
//         while (right != nullptr){
//             // if value not in seen, point left, update 
//             if (seen.find(right->val) == seen.end()){
//                 left->next = right;
//                 left = right;
//                 right = right->next;
//             }
//             // if in then skip this one 
//             else{
//                 right = right->next;
//             }
//         }
//         left->next = nullptr;
//         return head;
//     }
// };