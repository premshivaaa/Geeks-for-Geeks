class Solution {
    
  private:
    bool dfs(int node,int curr, vector<vector<int>>& adj, vector<int>& color){
        color[node] = curr;
        
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(dfs(it, !curr, adj, color) == false) return false;
            } else if (color[it] == curr){
                return false;
            }
        }
        return true;
    }
    
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i, 0, adj, color) == false) return false;
            }
        }
        
        return true;
    }
};