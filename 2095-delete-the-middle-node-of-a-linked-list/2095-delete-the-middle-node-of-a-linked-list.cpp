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
        int n=1;
        ListNode* curr=head;
        
        while(curr->next!=NULL){
            n++;
            curr=curr->next;
        }
        if(n==1){
            delete head;
            return NULL;
        }
        curr=head;
        for(int i=0;i<n/2-1;i++){
            curr=curr->next;
        }
        
        // cout<<curr->val<<" ";
        
        ListNode* temp=curr->next;
        curr->next=temp->next;
        delete temp;
        
        return head;
    }
};