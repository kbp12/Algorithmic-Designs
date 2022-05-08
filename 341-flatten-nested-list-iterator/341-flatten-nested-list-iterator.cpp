/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int j=0,n=0;
    vector<int>v;
    void solve(vector<NestedInteger> &A)
    {
        for(int i=0;i<A.size();i++)
        {
            if(A[i].isInteger()){
                v.push_back(A[i].getInteger());
            }else{
                solve(A[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &A) {
        solve(A);
        n=v.size();
    }

    int next() {
        j++;
        return v[j-1];
    }
    
    bool hasNext() {
        if(j==n)
            return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */