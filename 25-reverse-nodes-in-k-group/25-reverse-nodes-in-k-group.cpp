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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        vector<ListNode*>v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        int n = v.size();
        head = v[k-1];
        int i = k-2;
        int m = k;
        int j = 0;
        while(true){
            while(i>=j){
                head->next = v[i];
                head = v[i];
                i--;
            }
            j = m;
            m+=k;
            if(n>=m){
                i = m-1;
                continue;
            }
            i = j;
            while(i<n){
                head->next = v[i];
                head = v[i];
                i++;
            }
            break;
        }
        head->next = NULL;
        return v[k-1];
    }
};