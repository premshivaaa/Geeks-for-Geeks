// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for(auto edge : edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int topCity = n;
        int cityNo = -1;
        
        for(int city=0; city<n; city++){
            int counter = 0;
            for(int adjCity=0; adjCity<n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold) counter++;
            }
            if(counter <= topCity){
                topCity = counter;
                cityNo = city;
            }
        }
        return cityNo;
    }
};
