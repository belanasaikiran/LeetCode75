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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* prev = head; // point to the one the j left behind. 
        ListNode* slow = head; // move by one
        ListNode* fast = head; // move by two nodes

        

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(fast == nullptr) break;           
        }

        prev->next = slow->next;
        delete slow;  

        return head;
        
    }
};