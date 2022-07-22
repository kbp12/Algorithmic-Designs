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
        ListNode* cmin = NULL;
        ListNode* cmax = NULL;
        ListNode* temp = head;
        ListNode* temphead = NULL;
        while(temp){
            if(temp->val <x){
                if(cmin){
                    cmin->next = temp;
                    cmin = temp;
                }else{
                    cmin = temp;
                    head = cmin;
                }
            }else{
                if(cmax){
                    cmax->next = temp;
                    cmax = temp;
                }else{
                    cmax = temp;
                    temphead = cmax;
                }
            }
            temp = temp->next;
        }
        if(cmax)
            cmax->next = NULL;
        if(cmin){
            cmin->next = temphead;
            return head;
        }
        
        return temphead;
    }
};