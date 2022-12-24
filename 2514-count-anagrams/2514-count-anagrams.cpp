class Solution {
public:
    #define ll long long
    int N = 100001;
    ll factorialNumInverse[100005];
    ll naturalNumInverse[100005];
    ll fact[100005];
 
    void InverseofNumber(ll p){
        naturalNumInverse[0] = naturalNumInverse[1] = 1;
        for (int i = 2; i <= N; i++)
            naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
    }
    
    void InverseofFactorial(ll p){
        factorialNumInverse[0] = factorialNumInverse[1] = 1;
        for (int i = 2; i <= N; i++)
            factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
    }
 
    void factorial(ll p){
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % p;
        }
    }
 
    ll Binomial(ll N, ll R, ll p){
        ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
        return ans;
    }
    
    int countAnagrams(string s) {
        ll p = 1000000007;
        InverseofNumber(p);
        InverseofFactorial(p);
        factorial(p);
        stringstream str(s);
        string temp;
        long long ans = 1;
        while(str >> temp){
            int sz = temp.size();
            int a[26] = {};
            for(auto ch:temp){
                a[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                if(a[i]){
                    long long res = Binomial(sz, a[i], p);
                    ans = (ans*res)%p;
                    sz-=a[i];
                }
            }
        }
        return ans;
    }
};