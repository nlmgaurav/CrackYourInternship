class Solution {
public:
    // Floyd Warshall ALgo
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0 ; i<n ; i++){
            dist[i][i] = 0;
        }

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++ ){
                for(int j=0 ; j<n ; j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
                        if(dist[i][j] > dist[i][k] + dist[k][j]){
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        int ans = -1;
        int mini = INT_MAX;

        for(int i=0 ; i<n ; i++ ){
            int cnt = 0;
            for(int j=0 ; j<n ; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(mini >= cnt){
                mini = cnt;
                ans = i;
            }
        }
        return ans;

    }
};