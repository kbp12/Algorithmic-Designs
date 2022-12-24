class Solution {
public:
    
    int numTilings(int n) {
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 5;
    }
    int one = 1;
    int two = 2;
    int three = 5;
    int mod = 1000000007;
    int four;    
    for(int i=4;i<=n;i++){
        four = ((2*three)%mod +(one)%mod)%mod;
        one = two;
        two = three;
        three = four;
    }
    return four;
    }
};