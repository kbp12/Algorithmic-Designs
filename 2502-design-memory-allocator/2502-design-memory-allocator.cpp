class Allocator {
public:
    vector<int>v;
    int n;
    Allocator(int n) {
        this->n = n;
        v = vector<int>(n , 0);
        return;
    }
    
    int allocate(int size, int mID) {
        bool y = false;
        int c = 0 , idx = -1;
        for(int i=0;i<n;i++){
            if(v[i] == 0){
                c++;
            }else{
                c = 0;
            }
            if(c==size){
                idx = i-size+1;
                y = true;
                break;
            }
        }
        if(!y) return -1;
        for(int i=idx;i<idx+size;i++) v[i] = mID;
        return idx;
    }
    
    int free(int mID) {
        int c = 0;
        for(int i=0;i<n;i++){
            if(v[i] == mID){
                v[i] = 0;
                c++;
            }
        }
        return c;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */