class DisjointSet{
    vector<int> size_arr, rank, parent;
    
  public:
  
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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>> adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj.push_back({w, {u,v}});
        }
        sort(adj.begin(), adj.end());
        int mstW = 0;
        DisjointSet ds(V);
        
        for(auto it : adj){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUParent(u) != ds.findUParent(v)){
                mstW += w;
                ds.unionBySize(u, v);
            }
        }
        return mstW;
    }
};