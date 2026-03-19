class Solution {
    
  private:
    vector<int> toposort(int n, vector<vector<int>>& adj){
        vector<int> indegree(n, 0);
        vector<int> topo;
        queue<int> q;
        
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        
        return topo;
    }
    
  public:
    string findOrder(vector<string> &words) {
        int n = 26;
        vector<vector<int>> adj(n);
        vector<int> present(26, 0);  // its like vis array
        int count = 0;
        
        for(auto word : words){
            for(auto ch : word){
                if(!present[ch - 'a']){
                    present[ch - 'a'] = 1;
                    count++;
                }
            }
        }
        
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
        
        vector<int> topo = toposort(n, adj);
        
        string ans = "";
        for(auto it : topo){
            if(present[it]){
                ans += char(it + 'a');
            }
        }
        
        
        if(ans.size() != count) return "";
        
        return ans;
    }
};