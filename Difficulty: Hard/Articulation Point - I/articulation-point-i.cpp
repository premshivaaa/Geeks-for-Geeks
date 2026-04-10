class Solution {
    int timer = 1;
    unordered_set<int> st;
    
  private:
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, adj, tin, low);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    st.insert(node);
                }
                child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1){
            st.insert(node);
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        st.clear();
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, adj, tin, low);
            }
        }
        vector<int> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        
        if(ans.size() == 0) return {-1};
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};