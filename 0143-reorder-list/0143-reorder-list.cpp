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
    // Function to reverse the LL
    ListNode *reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL, *forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // Check for edge cases
        if(head->next == NULL || head->next->next == NULL)
            return;

        // Step 1 - Find middle of the LL with slow-fast pointer approach
        ListNode *slow = head, *fast = head, *slow_prev = NULL;
        while(fast != NULL && fast->next != NULL){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2 - Split the LL into 2 parts from the middle 
        // and reverse the second part
        ListNode *h1 = head, *h2;
        if(fast == NULL){
            h2 = reverse(slow);
            slow_prev->next = NULL;
        }
        else{
            h2 = reverse(slow->next);
            slow->next = NULL;
        }
        
        // Traverse both the LL while linking heads of both LL
        ListNode *next1 = h1->next, *next2 = h2->next;
        while(h1 != NULL && h2 != NULL){
            next1 = h1->next;
            next2 = h2->next;

            h1->next = h2;
            h2->next = next1;

            h1 = next1;
            h2 = next2;
        }
    }
};