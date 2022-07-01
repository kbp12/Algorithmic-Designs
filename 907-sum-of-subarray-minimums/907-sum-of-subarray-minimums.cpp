class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n),right(n);
        stack<int>mono_st;
        for(int i=0;i<n;i++){
            while(mono_st.size() && arr[mono_st.top()]>arr[i]){
                mono_st.pop();
            }
            if(mono_st.size()){
                left[i] = mono_st.top();
            }else{
                left[i] = -1;
            }
            mono_st.push(i);
        }
        stack<int>mono_st2;
        for(int i=n-1;i>=0;i--){
            while(mono_st2.size() && arr[mono_st2.top()]>=arr[i]){
                mono_st2.pop();
            }
            if(mono_st2.size()){
                right[i] = mono_st2.top();
            }else{
                right[i] = n;
            }
            mono_st2.push(i);
        }
        int ans = 0, mod = 1e9+7;
        for(int i=0;i<n;i++){
            long long a = ((i-left[i])*(right[i]-i))%mod;
            a = (a*arr[i])%mod;
            ans = (ans+a)%mod;
        }
        return ans;
    }
};