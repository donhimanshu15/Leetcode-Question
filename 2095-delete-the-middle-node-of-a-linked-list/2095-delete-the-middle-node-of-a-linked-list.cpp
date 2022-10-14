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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL) return NULL;
        int n=0;
         ListNode* cur =head;
        while(cur!=NULL) {
            n=n+1;
            cur=cur->next;
        }
        if(n==1 ) return NULL; 
int t=(n/2);
       ListNode* prev=NULL;
        cur=head;
        while(t--){
           prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        return head;
    }
};