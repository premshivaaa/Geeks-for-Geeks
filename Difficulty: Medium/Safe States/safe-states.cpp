class Solution {
    
  private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& check){
        vis[node] = 2;
        check[node] = 0;
        
        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(dfs(it, adj, vis, check) == true) return true;
            } else if (vis[it] == 2){
                return true;
            }
        }
        
        vis[node] = 1;
        check[node] = 1;
        return false;
    }
    
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        vector<int> vis(V, 0);
        vector<int> check(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, check);
            }
        }
        vector<int> safeNodes;
        
        for(int i=0; i<V; i++){
            if(check[i]){
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};