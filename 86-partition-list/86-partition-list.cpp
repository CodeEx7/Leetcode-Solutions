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
        ListNode *left_head=new ListNode(-1);
        ListNode *right_head=new ListNode(-1);
        ListNode *left=left_head, *right=right_head;
        
        while(head!=NULL){
            if(head->val>=x){
                right->next=head;
                right=right->next;
            }else{
                left->next=head;
                left=left->next;
            }
            head=head->next;
        }
        left->next=right_head->next;
        right->next=NULL;
        return left_head->next;
    }
};