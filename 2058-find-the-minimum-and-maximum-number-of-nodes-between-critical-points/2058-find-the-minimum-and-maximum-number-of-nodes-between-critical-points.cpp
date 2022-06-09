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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>list;
        while(head){
            list.push_back(head->val);
            head = head->next;
        }
        int n = list.size();
        vector<int>c_points;
        for(int i=1;i<n-1;i++){
            if((list[i]>list[i-1] && list[i]>list[i+1])||(list[i]<list[i-1] && list[i]<list[i+1])){
                c_points.push_back(i);
            }
        }
        if(c_points.size()<2) return {-1,-1};
        int mini = c_points[1]-c_points[0];
        int maxi = c_points[c_points.size()-1]-c_points[0];
        for(int i=2;i<c_points.size();i++){
            mini = min(mini,c_points[i]-c_points[i-1]);
        }
        return {mini,maxi};
    }
};