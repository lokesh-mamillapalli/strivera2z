#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> newboard (n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        FOR(i,0,n){
            FOR(j,0,m){
                if(grid[i][j] == 0){
                    newboard[i][j] = 0;
                }else{
                    if(i == 0 || i == n-1 || j == 0 || j == m-1){
                        newboard[i][j] = 2;
                        q.push({i,j});
                    }else{
                        newboard[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            newboard[x][y] = 2;
            int rows[] = {0,+1,0,-1};
            int cols[] = {-1,0,+1,0};
            FOR(i,0,4){
                if(x+rows[i] >= 0 && x+rows[i] < n && y+cols[i] >=0 && y+cols[i]<m){
                    if(newboard[(x+rows[i])][(y+cols[i])] == 1){
                        newboard[(x+rows[i])][(y+cols[i])] = 2;
                        q.push({ (x+rows[i]),(y+cols[i]) });
                    }
                }
            }
        }
        int count = 0;
        FOR(i,0,n){
            FOR(j,0,m){
                if(newboard[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};