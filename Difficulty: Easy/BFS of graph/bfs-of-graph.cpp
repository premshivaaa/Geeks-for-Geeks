class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        int V = adj.size();
        vector<int> vis(V, 0);
        queue<int> q;
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
            
        }
        
        return ans;
    }
};