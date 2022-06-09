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
        int c = 1;
        ListNode* temp = head, *prev = NULL, *last, *curr;
        while(temp){
            ListNode* temp2 = temp->next;
            if(c<left){
                prev = temp;
                c++; 
                temp = temp2;
                continue;
            }
            if(c==left){
                last = temp;
                curr = temp;
                temp = temp2;
                c++;
                continue;
            }
            if(c<=right){
                temp->next = curr;
                curr = temp;
            }else{
                break;
            }
            c++; 
            temp = temp2;
        }
        last->next = temp;
        if(prev == NULL) head = curr;
        else prev->next = curr;
        return head;
    }
};