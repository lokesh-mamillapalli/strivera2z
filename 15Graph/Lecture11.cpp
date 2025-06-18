#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
class Solution {
  public:
      void dfs(int vertex,int V,vector<vector<int>>&adj,vector<int>&visited,int parent,int&answer){
        visited[vertex] = 1;
        for(auto it:adj[vertex]){
            if(visited[it]==0){
                dfs(it,V,adj,visited,vertex,answer);
            }else{
                if(it != parent){
                    answer = 1;
                }
            }
        }
    }
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        int answer = 0;
        vector<int>visited(V,0);
        vector<vector<int>>adj(V);
        for(auto it:edges){
            int vertex1 = it[0];
            int vertex2 = it[1];
            adj[vertex1].push_back(vertex2);
            adj[vertex2].push_back(vertex1); 
        }
        FOR(i,0,V){
            if(visited[i] == 0){
                dfs(i,V,adj,visited,-1,answer);
            }
        }
        if(answer == 1){
            return true;
        }else{
            return false;
        }

        
    }
};