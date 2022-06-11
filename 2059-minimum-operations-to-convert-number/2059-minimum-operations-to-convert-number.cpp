class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int>q;
        q.push(start);
        int count = 1;
        unordered_set<int>uset;
        uset.insert(start);
        while(!q.empty()){
            int siz = q.size();
            for(int k=0;k<siz;k++){
                int f = q.front(); q.pop();
                for(int i=0;i<n;i++){
                    int a = f+nums[i];
                    if(a==goal) return count;
                    if(a>=0 && a<=1000 && uset.find(a)==uset.end()){
                        q.push(a);
                        uset.insert(a);
                    }
                    a = f-nums[i];
                    if(a==goal) return count;
                    if(a>=0 && a<=1000 && uset.find(a)==uset.end()){
                        q.push(a);
                        uset.insert(a);
                    }
                    a = f xor nums[i];
                    if(a==goal) return count;
                    if(a>=0 && a<=1000 && uset.find(a)==uset.end()){
                        q.push(a);
                        uset.insert(a);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};