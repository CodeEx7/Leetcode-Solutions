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
    //Merge two Lists
    ListNode* Merge(ListNode *h1, ListNode *h2){
        ListNode* dummy=new ListNode(-1);
        ListNode *curr1=h1, *curr2=h2;
        ListNode *head=dummy;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<curr2->val){
                dummy->next=curr1;
                curr1=curr1->next;
            }else{
                dummy->next=curr2;
                curr2=curr2->next;
            }
            dummy=dummy->next;
        }
        if(curr1==NULL){
            dummy->next=curr2;
        }
        if(curr2==NULL){
            dummy->next=curr1;
        }      
        
        return head->next;
    }
    
    //main working function
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1){
            return lists[0];
        } 
       ListNode* merged=Merge(lists[0], lists[1]);
        for(int i=2;i<lists.size();i++){
            merged=Merge(merged, lists[i]);
        }
        return merged;
    }
};