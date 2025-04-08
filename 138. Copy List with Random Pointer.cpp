/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



/*
1. 
    ways for each node map -> pair Node Node  
    map of nodes 

are all the values unique ? 
    if they are not 

2. 
    build the seq with next 
    3 3 3 
    n 0 n 

    for random
        find which idx points to || n * n to find the idx pos of each 

    MAP 
        idx -> Node 
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (!head) return head;
    
            Node* cur_head = nullptr;
            Node* tail = nullptr; 
            // make the sequential LL 
            int n = 0;
            Node* dummy = head;
            map<int, Node*> copy_positions;
            while (dummy != nullptr){
                Node* temp_node = new Node(dummy->val);
                if (cur_head == nullptr){
                    cur_head = temp_node;
                    tail = temp_node;
                }else{
                    tail->next = temp_node;
                    tail = tail->next;
                }
                copy_positions[n] = temp_node;
                n++;
                dummy = dummy->next;
            }
            // get random pointers, idx
            dummy = head;
            tail = cur_head;
            while (dummy != nullptr){
                // which node points to 
                Node* random = dummy->random;
                int idx = 0;
                while (random != nullptr){
                    random = random->next;
                    idx++;
                }
                // cout << n-idx << " ";
                // if not nullptr, make point to that node at that idx 
                if (dummy->random){
                    tail->random = copy_positions[n-idx];
                }
                dummy = dummy->next;
                tail = tail->next;
            }
            return cur_head;
        }
    };