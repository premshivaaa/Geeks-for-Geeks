class Solution {
    
  private:
    void dfs(int row, int col, vector<vector<int>>& image, int newColor, int initial, int n, int m){
        image[row][col] = newColor;
        
        int delrow[4] = {-1, 1, 0, 0};
        int delcol[4] = {0, 0, -1, 1};
        
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initial){
                dfs(nrow, ncol, image, newColor, initial, n, m);
            }
        }
    }
    
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        int initial = image[sr][sc];
        if(initial == newColor) return image;
        
        int n = image.size();
        int m = image[0].size();
        
        
        dfs(sr, sc, image, newColor, initial, n, m);
        
        
        return image;
    }
};