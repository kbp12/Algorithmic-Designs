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

//   0
// temp

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=NULL;
        ListNode* res;
        while(head){
            if(head->val!=0){
                ans->val += head->val;
            }else{
                ListNode* temp = new ListNode(0);
                if(ans==NULL){
                    ans = temp;
                    res = ans;
                }else{
                    if(head->next){
                        ans->next = temp;
                        ans = ans->next;
                    }
                }
            }
            head = head->next;
        }
        return res;
    }
};