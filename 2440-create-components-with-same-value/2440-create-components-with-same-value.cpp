class Solution {
public:
    int dfs(vector<vector<int>> &tree, vector<int> &nums, vector<bool> &visited, int s, int val, int &count) {
        visited[s] = true;
        int sum = nums[s];
        for(int child : tree[s]) {
            if(!visited[child]) {
                sum += dfs(tree, nums, visited, child, val, count);
            }
        }
        visited[s] = false;
        if(val == sum) {
            count++;
            return 0;
        }
        return sum;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int i, n = nums.size(), sum = 0, ans = 0;
        vector<vector<int>> tree(n);
        for(auto &edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        for(int num : nums) {
            sum += num;
        }
        vector<bool> visited(n);
        for(i = 1; i <= sqrt(sum); i++) {
            if((sum % i) == 0) {
                int count = 0;
                dfs(tree, nums, visited, 0, i, count);
                if(count == sum / i) {
                    ans = max(ans, count - 1); 
                }
                count = 0;
                dfs(tree, nums, visited, 0, sum / i, count);
                if(count == i) {
                    ans = max(ans, count - 1); 
                }
            }
        }
        return ans;
    }
};