#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int i,int j,vector<vector<vector<pair<int, int>>>>& adj,vector<vector<int>>& image,int color,vector<vector<int>>&visited) {
        image[i][j] = color;
        visited[i][j] = 1;
        for(auto it:adj[i][j]){
            int x = it.first;
            int y = it.second;
            if(visited[x][y] == 0){
                image[x][y] = color;
                visited[x][y] = 1;
                dfs(x,y,adj,image,color,visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(m));
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int colour = image[i][j];

                for(int x = -1;x<=1;x++){
                    for(int y = -1;y<=1;y++){
                        if(x == 0 || y == 0){
                            if(x == 0 && y == 0){

                            }else{
                                if(i+x >= 0 && i+x < n && j+y >=0 && j+y < m){
                                    if(colour == image[i+x][j+y]){
                                        adj[i][j].push_back({i+x,j+y});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        dfs(sr,sc,adj,image,color,visited);
        return image;
    }
};