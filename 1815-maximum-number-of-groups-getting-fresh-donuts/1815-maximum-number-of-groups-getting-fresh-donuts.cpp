class Solution {
public:
    int maxHappyGroups(int n, vector<int>& v) {
        vector<int> cnt(n, 0);
        for(auto x:v) cnt[x % n]++;
        State state;
        for(int i=1;i<n;i++) state.add(i, cnt[i]);
        return dp(0, n, state) + cnt[0];
    }
    
    struct State {
        bool empty(int i) const{
            auto x = mask >> (i*5);
            return (x & 0b11111) == 0;
        }
        
        void add(int i, long long val){
            mask += val << (i*5);
        }
        
        State minus1(int i) const{
            auto res = *this;
            res.mask -= 1LL<<(i*5);
            return res;
        }
        
        long long mask = 0;
    };
    
    int dp(int numDonut, int n, State state){
        if(state.mask == 0) return 0;
        if(mdp.count(state.mask)) return mdp[state.mask];
        auto& res = mdp[state.mask];
        for(int i=1;i<n;i++)
            if(!state.empty(i)) res = max(res, dp((numDonut + i)%n, n, state.minus1(i)));
 
        res += (numDonut == 0) ? 1 : 0;
        return res; 
    }

    unordered_map<long long, int> mdp; //numDonut, state    
};