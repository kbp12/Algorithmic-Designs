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
        int count = 0;
        ListNode* temp = head;
        while(head != NULL)
        {
            head = head->next;
            count++;
        }
        count = count - n + 1;
        head = temp;
        if(count == 1)
            return temp->next;
        int i=1;
        while(i<count-1)
        {
            head = head->next;
            i++;
        }
        ListNode* pre = head;
        if(head->next->next != NULL)
            head = head->next->next;
        else
            head = NULL;
        pre->next = head;
        head = temp;
        return head;
    }
};