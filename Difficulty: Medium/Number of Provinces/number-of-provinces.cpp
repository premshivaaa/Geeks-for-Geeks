// User function Template for C++

class DisjointSet{
  public:
    vector<int> size_arr, rank, parent;
    
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
        rank.resize(n+1, 0);
        size_arr.resize(n+1, 1);
    }
    int findUParent(int node){
        if(parent[node] == node) return node;
        
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);
        if(ultp_u == ultp_v) return;
        
        if(rank[ultp_u] < rank[ultp_v]){
            parent[ultp_u] = ultp_v;
        }
        else if(rank[ultp_v] < rank[ultp_u]){
            parent[ultp_v] = ultp_u;
        }
        else{
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);
        if(ultp_u == ultp_v) return;
        
        if(size_arr[ultp_u] < size_arr[ultp_v]){
            parent[ultp_u] = ultp_v;
            size_arr[ultp_v] += size_arr[ultp_u];
        }
        else{
            parent[ultp_v] = ultp_u;
            size_arr[ultp_u] += size_arr[ultp_v];
        }
    }
};


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1) ds.unionBySize(i, j);
            }
        }
        
        int counter = 0;
        for(int i=0; i<V; i++){
            if(ds.parent[i] == i) counter++;
        }
        
        return counter;
    }
};