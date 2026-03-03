// User function Template for C++

class Solution {
    
  private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis){
        vis[node] = 1;
        
        for(auto it : adjList[node]){
            if(!vis[it]){
                dfs(it, adjList, vis);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjList(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                count++;
                dfs(i, adjList, vis);
            }
        }
        return count;
    }
};