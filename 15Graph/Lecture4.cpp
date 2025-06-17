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
};
