/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA=headA;
        ListNode *currB=headB;
        int m=0, n=0;
        while(currA!=NULL){
            m++;
            currA=currA->next;
        }
        while(currB!=NULL){
            n++;
            currB=currB->next;
        }
        currA=headA;
        currB=headB;
        if(m>n){
            int size=m-n;
            while(size--){
                currA=currA->next;
            }
        }else{
            int size=n-m;
            while(size--){
                currB=currB->next;
            }
        }
        
        while(currA){
            if(currA==currB){
                return currA;
            }
            currA=currA->next;
            currB=currB->next;
        }
        return NULL;
    }
};