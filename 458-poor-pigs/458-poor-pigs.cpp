class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1) return 0;
        int times = (minutesToTest/minutesToDie)+1;
        int pigs = 1;
        while(true){
            int buc_count = 1;
            int pig = pigs;
            while(pig--){
                buc_count*=times;
            }
            if(buc_count>=buckets){
                return pigs;
            }
            pigs++;
        }
        return -1;
    }
};