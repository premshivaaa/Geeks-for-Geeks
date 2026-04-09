class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    void dfs_rev(int node, vector<int>& vis, vector<vector<int>>& adjT){
        vis[node] = 1;
        for(auto it : adjT[node]){
            if(!vis[it]){
                dfs_rev(it, vis, adjT);
            }
        }
    }
    
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        stack<int> st;
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        // sorting according to latest ones
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        // reversing adj list
        vector<vector<int>> adjT(V);
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it : adj[i]){

                adjT[it].push_back(i);
            }
        }
        
        // checking no.of scc
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs_rev(node, vis, adjT);
            }
        }
        return scc;
        
    }
};