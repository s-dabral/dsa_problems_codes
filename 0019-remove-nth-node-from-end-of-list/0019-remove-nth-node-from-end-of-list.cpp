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
    int cnt=0;//total no of nodes
    void f(ListNode* head)
    {
       while(head!=NULL)
       {
           cnt++;
           head=head->next;
       }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* temp1=head;
        f(temp1);
        int z=cnt-n+1;//count from starting position
        ListNode* prev;
        ListNode* next1;
        int c=0;
        if(z==1)
        {
           return head->next; 
        }
        while(temp!=NULL and temp->next!=NULL)
        {
            next1=temp->next;
            prev=temp;
            temp=temp->next;
            c++;
            if(c+1==z)
            {
                prev->next=next1->next;
            }  
        }
        return head;
    }
};