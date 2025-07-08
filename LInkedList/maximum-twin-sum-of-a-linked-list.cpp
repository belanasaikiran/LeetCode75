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
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* midBefore = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            midBefore = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "MID: " << slow->val << endl;
        cout << "mid before: " << midBefore->val << endl;

        ListNode* mid = slow;
        ListNode* prev = nullptr;
        // reverse the right part.
        ListNode* next = midBefore;
        ListNode* nextNext = next->next;
        while(nextNext != nullptr){
            next = nextNext;
            nextNext = next->next;
            next->next = prev;
            prev = next;
        }

        ListNode* L2 = next;
        midBefore->next = nullptr;
        ListNode* L1 = head;
        int maxSum = 0;
        while(L1 != nullptr && L2 != nullptr){
            maxSum = max(maxSum, L1->val + L2->val);
            L1 = L1->next; 
            L2 = L2->next;
        }        

        return maxSum;
    }
};