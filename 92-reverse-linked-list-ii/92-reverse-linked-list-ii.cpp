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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode* dummy = new ListNode(0,head);
        head=dummy;
        int count=0;
        ListNode* prev=head;;
        while(count<left-1){
            prev=prev->next;
            count++;
        }
        ListNode* pre= NULL;
        ListNode* cur=prev->next;
        ListNode* forw;
        while(count<right){
            forw=cur->next;
            cur->next=pre;
            pre=cur;
            cur=forw;
            count++;
            
        }
        prev->next=pre;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=cur;
        return dummy->next;
    }
};