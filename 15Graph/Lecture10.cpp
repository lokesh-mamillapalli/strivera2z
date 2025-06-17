class Solution {
public:

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 ||grid[i][j] == 2){
                    for(int x = -1;x<=1;x++){
                        for(int y = -1;y<=1;y++){
                            if(x == 0 || y == 0){
                                if(x == 0 && y == 0){
                                }else{
                                    if(i+x >= 0 && i+x < n && j+y >=0 && j+y < m){
                                        if(grid[i+x][j+y] == 1 ||grid[i+x][j+y] == 2){
                                            adj[i][j].push_back({i+x,j+y});
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        int last = 0;

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            grid[x][y] = 2;
            int time = q.front().second;
            q.pop();
            last = time;
            time = time + 1;
            for(auto it:adj[x][y]){
                int x1= it.first;
                int y1 = it.second;
                if(visited[x1][y1] == 0){
                    visited[x1][y1] = 1;
                    q.push({{x1,y1},time});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return last;      
        
    }


};