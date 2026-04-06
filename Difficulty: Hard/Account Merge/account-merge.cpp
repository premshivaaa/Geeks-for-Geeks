class DisjointSet{
  public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
  public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        int n = arr.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<arr[i].size(); j++){
                string mail = arr[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto it : mapMailNode){
            int node = ds.findUParent(it.second);
            string mail = it.first;
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
