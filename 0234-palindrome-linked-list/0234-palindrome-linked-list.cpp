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
  bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    ListNode *next, *prev = new ListNode();

    while(fast && fast->next) {
      // for finding middle
      slow = slow->next;
      fast = fast->next->next; 

      // reversing first half
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
 
    // for edge cases
    if(fast) slow = slow->next;
    head = prev;

    // comparing first half to second one
    while(slow) {
      if(head->val != slow->val) return false;
      head = head->next, slow = slow->next;
    }
    return true;
  }
};