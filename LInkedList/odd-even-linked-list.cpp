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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* prevEven = even;

        while(even && even->next){
                odd->next = even->next;
                odd = odd->next;
                even->next = even->next->next;
                even = even->next;
        }

        // cout << "after loop even: " << even->val << endl;
        odd->next = prevEven;

        return head;
        
    }
};