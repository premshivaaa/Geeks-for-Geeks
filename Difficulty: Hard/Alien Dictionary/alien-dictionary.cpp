class Solution {
    
  private:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    
  public:
    string findOrder(vector<string> &words) {
        int n = 0;
        vector<int> present(26, 0);
        
        for(auto word : words){
            for(auto ch : word){
                if(!present[ch - 'a']){
                    present[ch - 'a'] = 1;
                    n++;
                }
            }
        }
        vector<vector<int>> adj(26);
        
        for(int i=0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            
            if(s1.size() > s2.size() && s1.substr(0, len) == s2){
                return "";
            }
            
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(26, adj);
        
        string ans = "";
        for(auto idx : topo){
            if(present[idx]){
                ans += char(idx + 'a');
            }
        }
        
        if(ans.size() != n) return "";
        
        return ans;
    }
};