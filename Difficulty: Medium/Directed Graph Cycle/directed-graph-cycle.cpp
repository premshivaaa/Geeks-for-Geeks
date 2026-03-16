class Solution {
    
  private:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis) == true) return true;
            } else if (pathVis[it] == 1){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};