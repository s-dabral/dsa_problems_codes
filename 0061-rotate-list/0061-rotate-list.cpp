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

    ListNode * rotate(ListNode * head){

        ListNode * prev = NULL;
        ListNode * curr = head;

        while(curr->next!=NULL){
            prev = curr;
            curr = curr->next;
        }

        curr->next = head;
        prev->next = NULL;
        return curr;

    }

    int getlength(ListNode * head){
        ListNode * p = head;
        int count =0;
        while(p!=NULL){
            p=p->next;
            count++;
        }
        return count;

    }



    ListNode* rotateRight(ListNode* head, int k) {

        ListNode * curr = head;

        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        int count = 0;
        int length = getlength(head);
        k=k%length;

        while(count < k){
            curr = rotate(curr);
            count++;
        }

        return curr;
        
    }
};