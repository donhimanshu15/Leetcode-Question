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
    ListNode* partition(ListNode* head, int x) {
      ListNode* dummy= new ListNode(0,head);
        head=dummy;
        ListNode* last=dummy;
        int cnt=0;
        ListNode* temp=head->next;
        ListNode* rep;
        while(last->next!=NULL){
            last=last->next;
            cnt++;
        }
       if (cnt==1)  return head->next;
       
     while(cnt--){
         if(temp->val>=x) {
         if(head->next->next) {  head->next=head->next->next; }
             else return dummy->next;
             rep=temp;
             temp=temp->next;
             rep->next=NULL;
             last->next=rep;
             last=last->next;
             
         }
         else{
             head=head->next;
             temp=temp->next;
         }
         
     }
        return dummy->next;
    }
};