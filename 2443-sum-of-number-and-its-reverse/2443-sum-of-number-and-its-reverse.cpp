class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        for(int i=1;i<=num;i++){
            int r = i;
            int val = 0;
            while(r){
                int rem = r%10;
                val = val*10 + rem;
                r = r/10;
            }
            if(i+val==num) return true;
        }
        return false;
    }
};