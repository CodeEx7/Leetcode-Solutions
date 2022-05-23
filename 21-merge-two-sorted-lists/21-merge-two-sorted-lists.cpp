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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *curr1=l1, *curr2=l2;
        ListNode *dummy=new ListNode(-1);
        ListNode *head=dummy;
        
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val < curr2->val){
            dummy->next=curr1;
            curr1=curr1->next;
            }else{
                dummy->next=curr2;
                curr2=curr2->next;
            }
            dummy=dummy->next;
        }
        if(curr1!=NULL){
            dummy->next=curr1;
        }else{
            dummy->next=curr2;
        }
        return head->next;
    }
};