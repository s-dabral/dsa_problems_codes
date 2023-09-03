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
    ListNode* swapNodes(ListNode* head, int k) {
    if(head->next==NULL){
        return head;
    }
    ListNode*temp=head;
    int s=0;
    while(temp!=NULL){
        temp=temp->next;
        s++;
    }
    ListNode*n1=head;
      int t=1;
      while(t!=k){
         n1=n1->next;
         t++;
      }
      ListNode*n2=head;
      t=1;
      while(t!=s+1-k){
          n2=n2->next;
          t++;
      }
      swap(n1->val,n2->val);
      return head;
    }
};