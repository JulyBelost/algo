// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        } else if(!l2) {
            return l1;
        }
        ListNode * lr;
        if(l1->val < l2->val){
            lr = l1;
            l1 = l1->next;
        } else {
            lr = l2;
            l2 = l2->next;
        }
        ListNode * li = lr;
        while(!(l1 == NULL && l2 == NULL)){
            if(l1 != NULL && (l2 == NULL || (l1->val < l2->val))){
                li->next = l1;
                l1 = l1->next;
            } else {
                li->next = l2;
                l2 = l2->next;
            }
            li = li->next;
        }
        return lr;
    }
};
