#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited (n,vector<int>(m,-1));
        FOR(i,0,n){
            FOR(j,0,m){
                if(grid[i][j] == 1){
                    visited[i][j] = 0;
                }
            }  
        }
        vector<set<pair<int,int>>> vec_of_sets;
        FOR(i,0,n){
            FOR(j,0,m){
                if(visited[i][j] == 0){
                    set<pair<int, int>> s;
                    s.insert({i,j});
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        visited[x][y] = 1;
                        int rows[] = {0,+1,0,-1};
                        int cols[] = {-1,0,+1,0};
                        FOR(i,0,4){
                            if(x+rows[i] >= 0 && x+rows[i] < n && y+cols[i] >=0 && y+cols[i]<m){
                                if(visited[(x+rows[i])][(y+cols[i])] == 0){
                                    visited[(x+rows[i])][(y+cols[i])] = 1;
                                    q.push({ (x+rows[i]),(y+cols[i]) });
                                    s.insert({ (x+rows[i]),(y+cols[i])});
                                }
                            }
                        }
                    }
                    vec_of_sets.push_back(s);
                }
            }  
        }
        int number = vec_of_sets.size();
        FOR(i,0,number){
            auto it = vec_of_sets[i].begin();
            int x = it->first;
            int y = it->second;
            for(auto it = vec_of_sets[i].begin(); it != vec_of_sets[i].end(); ) {
                int x1 = it->first;
                int y1 = it->second;
                x1 = x1-x;
                y1 = y1-y;
                it = vec_of_sets[i].erase(it);
                vec_of_sets[i].insert({x1,y1});
            }

        }
        int count = 0;
        FOR(i,0,number){
            int flag = 0;
            FOR(j,i+1,number){
                if(vec_of_sets[i] == vec_of_sets[j]){
                    flag = 1;
                }
            }
            if(flag == 0){
                count++;
            }
        }
        return count;
    }
};
