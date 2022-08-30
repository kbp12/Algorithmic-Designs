/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        for(int i=0;i<n;i++){
            bool cele = true;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(!knows(j,i) or knows(i,j)){
                    cele = false;
                    break;
                }
            }
            if(cele) return i;
        }
        return -1;
    }
};