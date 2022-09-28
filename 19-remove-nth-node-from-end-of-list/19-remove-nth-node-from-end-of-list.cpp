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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        int len=0;
        ListNode *temp=head,*prev=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        
        int remain=len-n;
        if(remain==0){
            ListNode *temp=head->next;
            delete head;
            return temp;
        }
        ListNode *curr=head;
        while(remain--){
            prev=curr;
            curr=curr->next;
            
        }
        prev->next=curr->next;
        delete curr;
        return head;
    }
};