#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>path;
        vector<int>visited(V,0);
        visited[0] = 1;
        path.push_back(0);
        dfs(0,V,adj,visited,path);
        return path;
    }

    void dfs(int vertex,int V,vector<int>adj[],vector<int>&visited,vector<int>&path){
        for(auto it:adj[vertex]){
            if(visited[it]==0){
                visited[it] = 1;
                path.push_back(it);
                dfs(it,V,adj,visited,path);
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int>visited(V,0);
        vector<int>path;
        q.push(0);
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            if(visited[vertex]==0){
                visited[vertex] = 1;
                path.push_back(vertex);
                for(auto it:adj[vertex]){
                    q.push(it);
                }
            }
        }
        return path;
    }

    // 1 is slow 2 is fast;

    vector<int> bfsOfGraph2(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int>visited(V,0);
        vector<int>path;
        q.push(0);
        path.push_back(0);
        visited[0] = 1;
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(auto it:adj[vertex]){
                if(visited[it]==0){
                    path.push_back(it);
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return path;
    }
};


int main() {
    int V = 5;
    vector<int> adj[5];
    adj[0] = {2,3,1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    Solution sol;

    vector<int> dfs_path = sol.dfsOfGraph(V, adj);
    cout << "DFS Path: ";
    for (int v : dfs_path) cout << v << " ";
    cout << endl;

    vector<int> bfs_path1 = sol.bfsOfGraph(V, adj);
    cout << "BFS Path1: ";
    for (int v : bfs_path1) cout << v << " ";
    cout << endl;

    vector<int> bfs_path2 = sol.bfsOfGraph2(V, adj);
    cout << "BFS Path2: ";
    for (int v : bfs_path2) cout << v << " ";
    cout << endl;
}
