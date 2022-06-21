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
        ListNode* dummy = new ListNode(0, head);
        head = dummy;
        int count = 0;
        ListNode* leftPrev = head;
        
        while (count < left-1){
            leftPrev = leftPrev->next;
            count++;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = leftPrev->next;
        ListNode* forw;
        
        while (count < right){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }
        
        leftPrev->next = prev;
        ListNode* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = curr;
        
        return dummy->next;
    }
};