class Solution {
    int n, m;
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, bool &boundary) {

        vis[row][col] = 1;

        if (row == 0 || row == n - 1 || col == 0 || col == m - 1)
            boundary = true;

        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                mat[nrow][ncol] == 1 &&
                !vis[nrow][ncol]) {

                dfs(nrow, ncol, mat, vis, boundary);
            }
        }
    }

public:
    int countGroups(vector<vector<int>> &mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (mat[i][j] == 1 && !vis[i][j]) {

                    bool boundary = false;

                    dfs(i, j, mat, vis, boundary);

                    if (!boundary)
                        count++;
                }
            }
        }

        return count;
    }
};