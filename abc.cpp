#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
class Solution {
  public:
  
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

        queue<pair<int,int>> q;
        
        FOR(i,0,V){
            if(visited[i] == 0){
                q.push({i,-1});
                visited[i] = 1;
                while(!q.empty()){
                    int vertex = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto it:adj[vertex]){
                        if(visited[it]==0){
                            visited[it] = 1;
                            q.push({it,vertex});
                        }else{
                            if(it == parent){
                            }else{
                                return true;
                            }
                        }
                    }
                }
            
            }
        }
        return false;
    }
};