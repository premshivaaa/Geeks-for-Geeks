class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0] = 0;
        
        priority_queue< pair<int,pair<int,int>>, 
        vector<pair<int, pair<int,int>>>, 
        greater<pair<int,pair<int,int>>> > pq;
        pq.push({0, {0,0}});
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};
        
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dif = pq.top().first;
            pq.pop();
            if(row == n-1 && col == m-1) return dif;
            
            
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max( abs(mat[nrow][ncol] - mat[row][col]), dif);
                    
                    if(newEffort < efforts[nrow][ncol]){
                        efforts[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};
