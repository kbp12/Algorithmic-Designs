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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        map<int,int>cnt;
        ListNode* temp = head;
        while(temp){
            cnt[temp->val]++;
            temp = temp->next;
        }
        ListNode* ans = nullptr;
        while(head){
            if(cnt[head->val]==1){
                if(ans==nullptr){
                    ans = head;
                    temp = head;
                }else{
                    temp->next = head;
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        if(temp) temp->next = nullptr;
        return ans;
    }
};