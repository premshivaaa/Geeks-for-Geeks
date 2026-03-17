class Solution {
    
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> vis(V, 0);
        vector<int> ans;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};