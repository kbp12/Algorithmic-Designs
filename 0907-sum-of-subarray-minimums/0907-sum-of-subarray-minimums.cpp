class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>l(n),r(n);
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(st1.size() and arr[st1.top()]>arr[i])     st1.pop();
            if(st1.size())  l[i] = st1.top();
            else     l[i] = -1;
            st1.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(st2.size() and arr[st2.top()]>=arr[i])      st2.pop();
            if(st2.size()) r[i] = st2.top();
            else r[i] = n;
            st2.push(i);
        }
        int ans = 0, mod = 1e9+7;
        for(int i=0;i<n;i++){
            long long temp = (i-l[i]);
            temp = (temp*(r[i]-i))%mod;
            temp = (temp*arr[i])%mod;
            ans = (ans+temp)%mod;
        }
        return ans;
    }
};