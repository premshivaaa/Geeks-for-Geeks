class Solution {
  private:
    void traversal(int node, vector<vector<int>>& adj, int vis[], vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                traversal(it, adj, vis, ans);
            }
        }
    }
    
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        int n = adj.size();
        int vis[n] = {0};
        
        traversal(0, adj, vis, ans);
        
        return ans;
    }
};