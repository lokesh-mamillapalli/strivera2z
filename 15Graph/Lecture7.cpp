class Solution {
public:

    void bfsOfGraph(int vertex,int V,vector<int>&visited,vector<vector<int>>&adj) {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
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