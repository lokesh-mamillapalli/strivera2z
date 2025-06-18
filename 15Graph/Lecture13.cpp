#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> answer(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        FOR(i,0,n){
            FOR(j,0,m){
                if(mat[i][j] == 0){
                    answer[i][j] = 0;
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            answer[x][y] = d;
            d++;
            int rows[] = {0,+1,0,-1};
            int cols[] = {-1,0,+1,0};
            FOR(i,0,4){
                if(x+rows[i] >= 0 && x+rows[i] < n && y+cols[i] >=0 && y+cols[i]<m){
                    if(visited[(x+rows[i])][(y+cols[i])] == 0){
                        visited[(x+rows[i])][(y+cols[i])] = 1;
                        q.push( { { (x+rows[i]),(y+cols[i]) } , d } );
                    }
                }
            }
        }
        return answer;
    }
};