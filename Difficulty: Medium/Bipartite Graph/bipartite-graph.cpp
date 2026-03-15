class Solution {
    
  private:
    bool check(int node, int V, vector<vector<int>> &adj, vector<int>& colors){
        queue<int> q;
        q.push(node);
        colors[0] = 0;
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(colors[it] == -1){
                    colors[it] = !colors[node];
                    q.push(it);
                } else if(colors[node] == colors[it]){
                    return false;
                }
            }
        }
        return true;
    }
    
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> colors(V, -1);
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0; i<V; i++){
            if(colors[i] == -1){
                if(check(i, V, adj, colors) == false) return false;
            }
        }
        
        return true;
    }
};