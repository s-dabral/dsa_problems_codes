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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;

        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        stack<int>st;
        ListNode* temp=prev;
        st.push(temp->val);
        temp=temp->next;

        while(temp!=NULL)
        {
            if(st.top()<=temp->val){
                st.push(temp->val);
                temp=temp->next;
            }
            else
            {
                temp=temp->next;
            }
        }

        ListNode* tem= new ListNode(st.top());
        ListNode* ans=tem;
        st.pop();

        while(!st.empty())
        {
            ListNode* templ= new ListNode(st.top());
            tem->next=templ;
            tem=tem->next;
            tem->next=NULL;
            st.pop();
        }


        return ans;
        
    }
};