class Solution {
public:

    void bfsOfGraph(int vertex,int V,vector<int>&visited,vector<vector<int>>adj) {
        queue<int> q;
        vector<int>path;
        q.push(vertex);
        path.push_back(vertex);
        visited[vertex] = 1;
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
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int vertex1 = it[0];
            int vertex2 = it[1];
            adj[vertex1].push_back(vertex2);
            adj[vertex2].push_back(vertex1); 
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                count++;
                bfsOfGraph(i,n,visited,adj);
            }
        }
        return count;
    }
};