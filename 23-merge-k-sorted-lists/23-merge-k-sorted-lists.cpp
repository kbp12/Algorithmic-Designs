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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        ListNode* t;
        for(int i=0;i<n;i++){
            t = lists[i];
            while(t){
                pq.push(t->val);
                t = t->next;
            }
        }
        ListNode* ans;
        if(pq.empty()){
            return NULL;
        }else{
            ans = new ListNode(pq.top());
            pq.pop();
        }
        ListNode * prev = ans;
        while(pq.size()){
            ListNode * curr = new ListNode(pq.top());
            pq.pop();
            prev->next = curr;
            prev = curr;   
        }
        prev->next = NULL;
        return ans;
    }
};