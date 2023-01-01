#define ll long long
#define pb push_back 
class BookMyShow {
public:
   
    int n;
    int m;
    int x;
    vector<ll> A;
    vector<ll> tree;
    vector<ll> lazy;
    int cur=0;//this will tell us the range till which we have already made elements 0
    void build(int node, int start, int end)

    {
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
        lazy[node]=A[start];
    }
    else
    {
        int mid = (start + end) / 2;
   
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
      
        tree[node] = tree[2*node] + tree[2*node+1];
        lazy[node]=max(lazy[2*node],lazy[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] = val;
        tree[node] = val;
        lazy[node]=val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
        lazy[node]=max(lazy[2*node],lazy[2*node+1]);
    }
}

ll query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

ll query2(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return -1;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return lazy[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    ll p1 = query2(2*node, start, mid, l, r);
    ll p2 = query2(2*node+1, mid+1, end, l, r);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    return max(p1,p2);
}
    BookMyShow(int N, int M) {
        n=N;
        m=M;
        x=m;
        A.assign(N,M);
        tree.assign(4*N,0);
        lazy.assign(4*N,0);
        build(1,0,N-1);
        
        
        
    
        
    }
    
    
vector<int> gather(int k, int maxRow) {
    
        
        int l=0;
        int r=n;
        while(l+1<r){
            int mid=(l+r)/2;
            if(query2(1,0,n-1,cur,mid)<k){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        //if(r==n)return {};
        if(query2(1,0,n-1,cur,r-1)>=k){
            r--;
        }
        if(r>maxRow)return {};
        int c=m-A[r];
        update(1,0,n-1,r,A[r]-k);
        return {r,c};
        
        
        
        
       
        
        
    }
    
    bool scatter(int k, int maxRow) {
        int l=0;
        int r=n;
        
        while(l+1<r){
            int mid=(l+r)/2;
            //cout<<mid<<endl;
            //cout<<cur<<endl;
            //cout<<query(1,0,n-1,cur,mid)<<endl;;
            if(query(1,0,n-1,cur,mid)<k){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        //cout<<r<<endl;
        //if(r==n)return 0;
        l=r;
        //cout<<l<<endl;
        if(query(1,0,n-1,cur,l-1)>=k){
            l--;
        }
        if(l>maxRow)return 0;
        ll s=(l>0)?query(1,0,n-1,cur,l-1):0;
        ll rem=k-s;
        cur=l;
        update(1,0,n-1,l,A[l]-rem);
        
//         for(int i=0;i<=l;i++){
//             if(k>A[i]){
//                 k-=A[i];
//                 update(1,0,n-1,i,0);
//             }
//             else{
//                 A[i]-=k;
//                 update(1,0,n-1,i,A[i]);
//             }
            
//         }
        
        
        
        
        
        
        return 1;
        
    }
};
