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
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* ahead;
        int k=0;
        while(curr!=NULL and k<2){
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
            k++;
        }
        head->next=swapPairs(curr);
        return prev;
    }
};