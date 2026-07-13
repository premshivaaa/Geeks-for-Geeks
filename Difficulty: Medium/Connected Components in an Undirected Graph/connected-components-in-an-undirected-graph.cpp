class Solution {
    vector<vector<int>> ans;
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& curr){
        vis[node] = 1;
        curr.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, curr);
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(V, 0);
        vector<vector<int>> ans;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                vector<int> curr;
                dfs(i, adj, vis, curr);
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};