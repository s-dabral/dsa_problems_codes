class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
// base case if 1 node or zero node 
        if(head == NULL|| head->next ==NULL){
            return head;
        }
        ListNode*temp = head;
        ListNode*prev = NULL;
// recuresive function -> return updated sorted head of newList
       ListNode *newhead = insertionSortList(head->next);
        ListNode*it = newhead;

// insert first node with updated new list
        while(it != NULL){
            // find position of first node 
            if(it->val < temp->val){
                prev = it;
                it = it->next;
            }else{
// first node is the smallest Node among all nodes then it would be our head node 
                if(prev==NULL){
                    temp->next = it;
                    newhead = temp;
                  
                }else{
// insert first node  between the new list 
                    prev ->next = temp;
                    temp->next = it;
                    }
                    break;
            }
        }
// first node is greatest among all nodes then it should be inserted in last 
        if(it == NULL){
            prev->next = temp;
            temp ->next = it; 
        }



        return newhead;
    }
};