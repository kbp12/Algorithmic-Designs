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
// [1,add(2)]  [2,add(3)] [3,add(4)] [4,add(5)] [5,NULL]

// temp = add(2)
// temp2 = add(2)
// prev = add(1)
// last = add(2)
    
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int c = 1;
        ListNode* temp = head, *prev = NULL, *last, *curr;
        
        while(temp){
            ListNode* temp2 = temp->next;
            if(c<left){
                prev = temp; 
            }else if(c==left){
                last = temp;   curr = temp;
            }else if(c<=right){
                temp->next = curr;    curr = temp;
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