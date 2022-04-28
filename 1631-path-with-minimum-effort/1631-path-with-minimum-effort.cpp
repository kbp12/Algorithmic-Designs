#define mydtype  pair<int, pair<int, int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h[0].size() - 1, m = h.size() - 1, l = 0, r = 0, ans = 0;
        priority_queue<mydtype,vector<mydtype>,greater<mydtype>>pq;
        pq.push({0, {0, 0}});
        while(l!=n || r!=m){
            auto curr = pq.top(); 
            
            // removing already visited nodes
            while (h[curr.second.second][curr.second.first]<0) {
                pq.pop(); curr = pq.top();
            }
            
            // updating looping variables
            ans = max(ans, curr.first);
            l = curr.second.first;
            r = curr.second.second;
            
            // updating pq with potential new neighbours
            if (l && h[r][l - 1] > 0) 
                pq.push({abs(h[r][l] - h[r][l-1]),{l-1,r}});
            if (r && h[r-1][l] > 0) 
                pq.push({abs(h[r][l] - h[r-1][l]), {l,r - 1}});
            if (l<n && h[r][l + 1] > 0) 
                pq.push({abs(h[r][l] - h[r][l + 1]), {l + 1, r}});
            if (r<m && h[r + 1][l] > 0) 
                pq.push({abs(h[r][l] - h[r + 1][l]), {l, r + 1}});
            // marking currNode as visited
            h[r][l] = -h[r][l];
        }
        return ans;
    }
};