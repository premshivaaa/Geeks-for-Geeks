class Solution {
    
  private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 2;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis) == false) return false;
            } else if(vis[it] == 2){
                return false;
            }
        }
        vis[node] = 1;
        return true;
    }
    
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>> adj(n);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis) == false) return false;
            }
        }
        
        return true;
    }
};