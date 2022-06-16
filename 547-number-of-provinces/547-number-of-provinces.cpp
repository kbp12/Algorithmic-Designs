
class Solution {
public:
    vector<int>parent,rank;
    
    int find(int x){
		if(parent[x]<0) return x;
		parent[x]=find(parent[x]);
        return parent[x];
	}
    
	void merge(int a,int b){
		int parent_a=find(a);
		int parent_b=find(b);
		if(parent_a==parent_b) return;
		if(rank[parent_a]>rank[parent_b]){
			parent[parent_b]=parent_a;
		}
		else if(rank[parent_a]<rank[parent_b]){
			parent[parent_a]=parent_b;
		}else{
			parent[parent_b]=parent_a;
			rank[parent_a]++;
		}
	}
    
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        parent.resize(n,-1);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && v[i][j]){
                    merge(i,j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) count++;
        }
        return count;
    }
};